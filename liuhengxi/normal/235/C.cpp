#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
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
namespace sam
{
	struct state{int len,link,next[26],cnt;}st[2*N];
	struct line{int next,to;}e[2*N];
	int ind,last,hd[N<<1],cnt;
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
				st[clone].cnt=0;
				for(;~p&&st[p].next[c]==q;p=st[p].link)st[p].next[c]=clone;
				st[q].link=st[cur].link=clone;
			}
		}
		++st[cur].cnt;
		last=cur;
	}
	void build(const char *s){init();for(;*s;++s)extend(*s-'a');}
	void adline(int u,int v)
	{
		e[cnt].to=v;
		e[cnt].next=hd[u];
		hd[u]=cnt++;
	}
	void buildtree()
	{
		F(i,0,ind)hd[i]=-1;
		F(i,1,ind)adline(st[i].link,i);
	}
	void dfs(int u)
	{
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;
			dfs(v);
			st[u].cnt+=st[v].cnt;
		}
	}
}
void zfunc(const char *s,int *z)
{
	int l=0,r=0;
	for(int i=1;s[i-1];++i)
	{
		if(i<=r)z[i]=min(r-i,z[i-l]);else z[i]=0;
		while(s[i+z[i]]==s[z[i]])++z[i];
		if(i+z[i]>r)r=i+z[i],l=i;
	}
}
int n,q,a[N<<1],z[N];
char s[N],t[N];
int main()
{
	scanf("%s",s);
	sam::build(s);
	sam::buildtree();
	sam::dfs(0);
	read(q);
	while(q--)
	{
		int u=0,c=1;
		long long ans=0;
		n=0;
		scanf("%s",t);
		while(t[n])++n;
		F(i,0,n)a[i]=a[i+n]=t[i]-'a';
		zfunc(t,z);
		while(n%c||c+z[c]<n)++c;
		for(int l=0,r=0;l<c;++l)
		{
			while(l<n&&r<l+n)
			{
				while(u&&!sam::st[u].next[a[r]])u=sam::st[u].link,l=r-sam::st[u].len;
				if(sam::st[u].next[a[r]])u=sam::st[u].next[a[r++]];
				else l=++r;
			}
			while(sam::st[sam::st[u].link].len>=n)u=sam::st[u].link;
			if(l<c)ans+=sam::st[u].cnt;
		}
		printf("%lld\n",ans);
	}
	return 0;
}