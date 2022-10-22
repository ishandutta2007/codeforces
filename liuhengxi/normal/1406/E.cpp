#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,pri[N],m,sqrtm,ans,now;
bool vis[N],in[N];
int main()
{
	read(n);
	if(n==1)return puts("C 1"),0;
	F(i,2,n+1)for(int j=i<<1;j<=n;j+=i)vis[j]=true;
	F(i,2,n+1)if(!vis[i])pri[m++]=i;
	while(sqrtm*sqrtm<m)++sqrtm;
	F(i,1,n+1)in[i]=true;
	now=n;
	F(i,0,m)
	{
		int x;
		if(i&&i%sqrtm==0)
		{
			puts("A 1");fflush(stdout);
			read(x);
			if(x!=now)
			{
				F(j,i-sqrtm,i)
				{
					printf("A %d\n",pri[j]);fflush(stdout);
					read(x);
					if(x)
					{
						ans=pri[j];
						break;
					}
				}
				break;
			}
		}
		printf("B %d\n",pri[i]);fflush(stdout);
		read(x);
		for(int j=pri[i];j<=n;j+=pri[i])now-=in[j],in[j]=false;
	}
	if(!ans)
	{
		F(j,(m-1)/sqrtm*sqrtm,m)
		{
			int x;
			printf("A %d\n",pri[j]);fflush(stdout);
			read(x);
			if(x)
			{
				ans=pri[j];
				break;
			}
		}
	}
	if(!ans)return puts("C 1"),0;
	int p=0;
	while(p<m&&pri[p]<ans)++p;
	for(;p<m;++p)while((long long)pri[p]*ans<=n)
	{
		int x;
		printf("A %d\n",pri[p]*ans);fflush(stdout);
		if(!read(x))break;
		ans*=pri[p];
	}
	printf("C %d\n",ans);
	return 0;
}