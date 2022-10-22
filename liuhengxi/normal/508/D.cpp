#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail return puts("NO"),0;
using namespace std;
const int M=2e5+5,N=3854;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int next,to;
}e[M];
int m,deg[N],n=3844,f[N],hd[N],cnt;
char s[5],ans[M];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int hash(char c){return c>='a'?c-'a'+36:(c>='A'?c-'A'+10:c-'0');}
char ihash(int x){return x<10?x+'0':(x<36?x-10+'A':x-36+'a');}
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	for(int &i=hd[u];~i;)
	{
		int v=e[i].to;i=e[i].next;
		dfs(v);
	}
	ans[--cnt]=ihash(u%62);
}
int main()
{
	read(m);
	F(i,0,n)f[i]=i,hd[i]=-1;
	F(i,0,m)
	{
		int u,v;
		scanf("%s",s);
		u=hash(s[0])*62+hash(s[1]);
		v=hash(s[1])*62+hash(s[2]);
		adline(u,v);
		++deg[v];--deg[u];
		f[find(u)]=find(v);
	}
	cnt=m+2;
	F(i,0,n)if(deg[i]>1||deg[i]<-1)fail;
	F(i,0,n)if(~hd[i])
	{
		F(j,i,n)if(~hd[j]&&find(i)!=find(j))fail;
		break;
	}
	F(i,0,n)if(deg[i]==1){F(j,i+1,n)if(deg[j]==1)fail;break;}
	F(i,0,n)if(deg[i]==-1){F(j,i+1,n)if(deg[j]==-1)fail;break;}
	F(i,0,n+1)if(!~deg[i]||i==n)
	{
		if(i==n)
		{
			F(j,0,n)if(~hd[j]){ans[0]=ihash(j/62),dfs(j);break;}
		}
		else ans[0]=ihash(i/62),dfs(i);
		break;
	}
	puts("YES");
	puts(ans);
	return 0;
}