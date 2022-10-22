#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=4860;
char s[1005];
int n,x,a[20],to[N][10],fail[N],m=1,q[N],qf,qr,va[N],c,f[N],g[N];
bool ban[N];
void dfs(int i,int sum)
{
	if(sum==0)
	{
		F(j,0,i)sum+=a[j];
		F(j,0,i)
		{
			int tmp=0;
			F(k,j,i-!j)
			{
				tmp+=a[k];
				if(sum%tmp==0)return;
			}
		}
		int u=0;
		F(k,0,i)to[u][a[k]]||(to[u][a[k]]=m++),u=to[u][a[k]];
		ban[u]=true;
		return;
	}
	F(j,1,min(10,sum+1))
	{
		a[i]=j;
		dfs(i+1,sum-j);
	}
}
void build()
{
	F(i,1,10)if(to[0][i])q[qr++]=to[0][i];
	while(qf<qr)
	{
		int u=q[qf++];
		F(i,1,10)(to[u][i]?fail[q[qr++]=to[u][i]]:to[u][i])=to[fail[u]][i];
	}
	F(i,0,m)if(!ban[i])va[c++]=i;
}
int main()
{
	scanf("%s",s);
	while(s[n])++n;
	read(x);
	dfs(0,x);
	build();
	memset(f,-0x3f,sizeof(f));
	f[0]=0;
	F(i,0,n)
	{
		int y=s[i]-'0';
		memcpy(g,f,sizeof(f));
		F(j,0,c)f[to[va[j]][y]]=max(f[to[va[j]][y]],g[va[j]]+1);
	}
	int ans=0;
	F(i,0,c)ans=max(ans,f[va[i]]);
	printf("%d\n",n-ans);
	return 0;
}