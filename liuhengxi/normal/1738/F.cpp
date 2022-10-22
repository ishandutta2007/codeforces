#include<cstdio>
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
constexpr int N=1005;
int tt,n,d[N],f[N],id[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
bool vis[N];
int main()
{
	read(tt);
	while(tt--)
	{
		read(n);
		F(i,0,n)read(d[i]),id[i]=i;
		sort(id,id+n,[](int u,int v){return d[u]>d[v];});
		F(i,0,n)f[i]=i,vis[i]=false;
		F(i,0,n)
		{
			int u=id[i];
			if(vis[u])continue;
			vis[u]=true;
			F(_,0,d[u])
			{
				printf("? %d\n",u+1);
				fflush(stdout);
				int v;
				--read(v);
				f[find(u)]=find(v);
				if(vis[v])break;
				vis[v]=true;
			}
		}
		printf("! ");
		F(i,0,n)printf("%d ",find(i)+1);
		puts("");
		fflush(stdout);
	}
	return 0;
}