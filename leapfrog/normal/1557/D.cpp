//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
typedef pair<int,int>pi;pi dp[1200005];vector<pi>v[1200005];
struct segm{pi tg,mx;}T[4800005];int n,m,tn[1200005],ut;
inline void pushup(int x) {T[x].mx=max(T[x<<1].mx,T[x<<1|1].mx);}
inline void allc(int x,pi c) {if(c!=make_pair(0,0)) T[x].mx=T[x].tg=c;}
inline void pushdw(int x) {allc(x<<1,T[x].tg),allc(x<<1|1,T[x].tg),T[x].tg=make_pair(0,0);}
inline void modif(int x,int l,int r,int dl,int dr,pi dc)
{
	if(l>dr||dl>r) return;else if(dl<=l&&r<=dr) return allc(x,dc);else pushdw(x);
	modif(x<<1,l,(l+r)>>1,dl,dr,dc),modif(x<<1|1,((l+r)>>1)+1,r,dl,dr,dc),pushup(x);
}
inline pi query(int x,int l,int r,int dl,int dr)
{
	if(l>dr||dl>r) return make_pair(0,0);else if(dl<=l&&r<=dr) return T[x].mx;else pushdw(x);
	return max(query(x<<1,l,(l+r)>>1,dl,dr),query(x<<1|1,((l+r)>>1)+1,r,dl,dr));
}
int main()
{
	read(n),read(m);
	for(int i=1,x,l,r;i<=m;i++)
	{
		read(x),read(l),read(r),v[x].push_back(make_pair(l,r));
		tn[++ut]=l,tn[++ut]=l+1,tn[++ut]=r,tn[++ut]=r+1;
	}
	sort(tn+1,tn+ut+1),ut=unique(tn+1,tn+ut+1)-tn-1;
	for(int i=1;i<=n;i++) for(int j=0;j<(int)v[i].size();j++)
	{
		int l=v[i][j].first,r=v[i][j].second;
		v[i][j].first=lower_bound(tn+1,tn+ut+1,l)-tn;
		v[i][j].second=lower_bound(tn+1,tn+ut+1,r)-tn;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<(int)v[i].size();j++)
		{
			int l=v[i][j].first,r=v[i][j].second;pi x=query(1,1,ut,l,r);
			x.first++,dp[i]=max(dp[i],x);
		}
		for(int j=0;j<(int)v[i].size();j++)
		{
			int l=v[i][j].first,r=v[i][j].second;
			pi x=dp[i];x.second=i,modif(1,1,ut,l,r,x);
		}
	}
	set<int>rs;for(int i=1;i<=n;i++) rs.insert(i);
	pi mx=make_pair(0,0);for(int i=1;i<=n;i++) mx=max(mx,dp[i]);
	int ps=0;for(int i=1;i<=n;i++) if(mx==dp[i]) {ps=i;break;}
	for(int i=ps;i;i=dp[i].second) rs.erase(i);
	printf("%d\n",(int)rs.size());for(auto x:rs) printf("%d ",x);
	return putchar('\n'),0;
}