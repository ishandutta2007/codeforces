#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
namespace sam
{
	struct state{int len,link,next[26];}st[2*N];
	int ind,last;
	void init(){st[0].link=-1;++ind;}
	void extend(int c)
	{
		int cur=ind++,p=last;
		st[cur].len=st[last].len+1;
		for(;~p&&!st[p].next[c];p=st[p].link)st[p].next[c]=cur;
		if(p==-1)st[cur].link=0;
		else
		{
			int q=st[p].next[c];
			if(st[q].len==st[p].len+1)st[cur].link=q;
			else
			{
				int clone=ind++;
				st[clone]=st[q];st[clone].len=st[p].len+1;
				for(;~p&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=clone;
				st[q].link=st[cur].link=clone;
			}
		}
		last=cur;
	}
	void build(const char *s){init();for(;*s;++s)extend(*s-'a');}
};
struct line
{
	int next,to;
}e[2*N];
using sam::build;using sam::st;
int n,hd[2*N],cnt,f[2*N];
long long ans;
char s[N],t[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		dfs(v);
		f[u]+=f[v];
	}
	ans=max(ans,st[u].len*(long long)f[u]);
}
int main()
{
	read(n);
	scanf("%s%s",s,t);
	build(s);
	F(i,0,sam::ind)hd[i]=-1;
	F(i,1,sam::ind)adline(st[i].link,i);
	for(int i=0,j=st[0].next[s[0]-'a'];i<n;j=st[j].next[s[++i]-'a'])f[j]+='1'-t[i];
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}