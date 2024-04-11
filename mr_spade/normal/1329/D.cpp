#include<cstdio>
#include<cstring>
#include<utility>
#include<vector>
#include<set>
#define mp make_pair
#define fi first
#define se second
using std::pair;
using std::mp;
using std::set;
using std::vector;
typedef pair<int,int> pii;
const int N=1e6+5,M=30;
int n;
char s[N];
set<int> S;
int cnt[M];
set<pii> e[M];
vector<pii> V;
int bit[N];
inline void add(int x,int k)
{
	while(x<=n)
		bit[x]+=k,x+=x&-x;
	return;
}
inline int ask(int x)
{
	int res=0;
	while(x)
		res+=bit[x],x&=x-1;
	return res;
}
inline int find(int k)
{
	int res=0;
	register int i;
	for(i=20;i>=0;i--)
		if((res|1<<i)<=n&&bit[res|1<<i]<=k)
			res|=1<<i,k-=bit[res];
	return res;
}
inline int color(int k)
{
	return s[k]-'a'+1;
}
inline void insert(int k)
{
	int p1=0,p2=0;
	set<int>::iterator it,jt;
	S.insert(k);it=S.find(k);cnt[color(k)]++;
	if(it!=S.begin())
	{
		jt=it;jt--;p1=*jt;
		if(color(*jt)!=color(k))
			e[color(*jt)].insert(mp(*jt,k)),e[color(k)].insert(mp(*jt,k));
	}
	jt=it;jt++;
	if(jt!=S.end())
	{
		p2=*jt;
		if(color(*jt)!=color(k))
			e[color(*jt)].insert(mp(k,*jt)),e[color(k)].insert(mp(k,*jt));
	}
	if(p1&&p2&&color(p1)!=color(p2))
		e[color(p1)].erase(mp(p1,p2)),e[color(p2)].erase(mp(p1,p2));
}
inline void erase(int k)
{
	int p1=0,p2=0;
	set<int>::iterator it,jt;
	it=S.find(k);
	if(it!=S.begin())
	{
		jt=it;jt--;p1=*jt;
		if(color(*jt)!=color(k))
			e[color(*jt)].erase(mp(*jt,k)),e[color(k)].erase(mp(*jt,k));
	}
	jt=it;jt++;
	if(jt!=S.end())
	{
		p2=*jt;
		if(color(*jt)!=color(k))
			e[color(*jt)].erase(mp(k,*jt)),e[color(k)].erase(mp(k,*jt));
	}
	if(p1&&p2&&color(p1)!=color(p2))
		e[color(p1)].insert(mp(p1,p2)),e[color(p2)].insert(mp(p1,p2));
	S.erase(k);cnt[color(k)]--;
	return;
}
inline void run(int l,int r)
{
	int d;
	printf("%d %d\n",ask(l-1)+1,ask(r));
	while(ask(r)!=(d=ask(l-1)))
		add(find(d)+1,-1);
	return;
}
inline void solve()
{
	int x;
	pii p;
	register int i;
	scanf("%s",s+1);
	for(i=1;i<=26;i++)
		cnt[i]=0,e[i].clear();
	V.clear();S.clear();
	n=strlen(s+1);
	for(i=2;i<=n;i++)
		if(s[i]==s[i-1])
			insert(i);
	for(i=1;i<=26;i++)
		if(cnt[i]*2>(int)S.size())
		{
			while(!e[i].empty())
				p=*e[i].begin(),V.push_back(mp(p.fi,p.se-1)),erase(p.fi),erase(p.se);
			while(!S.empty())
				x=*S.begin(),V.push_back(mp(x,x)),erase(x);
			goto end;
		}
	while((int)S.size()>1)
	{
		for(x=1,i=2;i<=26;i++)
			if(cnt[i]>cnt[x])
				x=i;
		p=*e[x].begin();V.push_back(mp(p.fi,p.se-1));erase(p.fi);erase(p.se);
	}
	while(!S.empty())
		x=*S.begin(),V.push_back(mp(x,x)),erase(x);
	end:;
	V.push_back(mp(1,n));
	printf("%d\n",(int)V.size());
	memset(bit+1,0,sizeof(int)*n);
	for(i=1;i<=n;i++)
		add(i,1);
	for(auto p:V)
		run(p.fi,p.se);
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}