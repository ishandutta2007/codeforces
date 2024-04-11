#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int pri[N],cnt;
bool vis[N],ch[N];
int n,k,l,a[N],d[N]={0,1}/*divisor*/,r[N],t[N],m;
void init()
{
	vis[0]=vis[1]=true;
	F(i,2,N)
	{
		if(!vis[i])d[pri[cnt++]=i]=2,t[i]=r[i]=1;
		F(j,0,cnt)
		{
			int x=i*pri[j];
			if(x>=N)break;
			vis[x]=true;
			if(i%pri[j]==0)
			{
				d[x]=d[r[x]=r[i]]*((t[x]=t[i]+1)+1);
				break;
			}
			d[x]=d[r[x]=i]<<(t[x]=1);
		}
	}
}
void solve(int k)
{
	int tmp=0;
	m=0;
	while(tmp<k&&m<n)tmp+=d[++m]-1;
	if(tmp<k)return m=n+1,void();
	l=m;
	F(i,1,m+1)ch[i]=true;
	F(i,m/3+1,m/2+1)if(!vis[i])if(tmp-k>1)ch[i]=false,--l,tmp-=2;
	F(i,m/2+1,m+1)if(!vis[i])if(tmp>k)ch[i]=false,--l,--tmp;
}
int main()
{
	init();
	read(n);read(k);
	solve(k);
	if(m>n)return puts("No"),0;
	puts("Yes");
	printf("%d\n",l);
	F(i,1,m+1)if(ch[i])printf("%d ",i);
	printf("\n");
	return 0;
}