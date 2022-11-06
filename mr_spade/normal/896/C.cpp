#include<cstdio>
#include<algorithm>
#include<vector>
#include<map>
#define iter iterator
#define lb lower_bound
#define mp make_pair
#define fi first
#define se second
#define int long long
using std::swap;
using std::sort;
using std::vector;
using std::map;
using std::pair;
using std::mp;
inline int qpow(int a,int b,int mod)
{
	int res=1;
	for(;b;a=(int)a*a%mod,b>>=1)
		if(b&1)
			res=(int)res*a%mod;
	return res;
}
typedef pair<int,int> pii;
typedef map<int,int> mii;
vector<pii> V;
mii M;
inline int len(mii::iter it)
{
	mii::iter jt=it;jt++;
	return jt->fi-it->fi;
}
inline void split(int pos)
{
	mii::iter it=M.lb(pos);
	if(it!=M.end()&&it->fi==pos)
		return;
	it--;
	int l=it->fi,v=it->se;
	M.erase(it);M.insert(mp(l,v));
	M.insert(mp(pos,v));
	return;
}
inline void add(int l,int r,int k)
{
	split(l);split(r+1);
	mii::iter it=M.lb(l),jt=M.lb(r+1);
	for(;it!=jt;it++)
		it->se+=k;
	return;
}
inline void assign(int l,int r,int k)
{
	split(l);split(r+1);
	mii::iter it=M.lb(l),jt=M.lb(r+1);
	M.erase(it,jt);M.insert(mp(l,k));
	return;
}
inline int select(int l,int r,int k)
{
	split(l);split(r+1);
	mii::iter it=M.lb(l),jt=M.lb(r+1);
	for(;it!=jt;it++)
		V.emplace_back(mp(it->se,len(it)));
	sort(V.begin(),V.end());
	for(auto i:V)
		if((k-=i.se)<=0)
			return V.clear(),i.fi;
}
inline int query_pow(int l,int r,int k,int mod)
{
	int res=0;
	split(l);split(r+1);
	mii::iter it=M.lb(l),jt=M.lb(r+1);
	for(;it!=jt;it++)
		res=(res+len(it)*qpow((int)(it->se%mod),k,mod)%mod)%mod;
	return res;
}
int n,m,seed,vmax;
inline int Rand()
{
	int ret=seed;
	seed=((int)seed*7+13)%1000000007;
	return ret;
}
signed main()
{
	int op,l,r,x,y;
	register int i;
	scanf("%lld%lld%lld%lld",&n,&m,&seed,&vmax);
	M.insert(mp(1,0));M.insert(mp(n+1,0));
	for(i=1;i<=n;i++)
		assign(i,i,Rand()%vmax+1);
	while(m--)
	{
		op=Rand()%4+1;
		l=Rand()%n+1;r=Rand()%n+1;
		if(l>r)
			swap(l,r);
		if(op==3)
			x=Rand()%(r-l+1)+1;
		else
			x=Rand()%vmax+1;
		if(op==4)
			y=Rand()%vmax+1;
		switch(op)
		{
			case 1:add(l,r,x);break;
			case 2:assign(l,r,x);break;
			case 3:printf("%lld\n",select(l,r,x));break;
			default:printf("%lld\n",query_pow(l,r,x,y));break;
		}
	}
	return 0;
}