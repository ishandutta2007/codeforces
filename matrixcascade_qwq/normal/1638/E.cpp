// Author:A weak man named EricQian
#include<bits/stdc++.h>
using namespace std;
#define infll 0x3f3f3f3f3f3f3f3f
#define inf 0x3f3f3f3f
#define Maxn 1000005
#define pb push_back
#define pa pair<int,int>
#define fi first
#define se second
typedef long long ll;
inline int rd()
{
	 int x=0;
	 char ch,t=0;
	 while(!isdigit(ch = getchar())) t|=ch=='-';
	 while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
	 return x=t?-x:x;
}
inline ll maxll(ll x,ll y){ return x>y?x:y; }
inline ll minll(ll x,ll y){ return x<y?x:y; }
inline ll absll(ll x){ return x>0ll?x:-x; }
inline ll gcd(ll x,ll y){ return (y==0)?x:gcd(y,x%y); }
int n,q;
ll addcol[Maxn];
struct BIT
{
	 ll tree[Maxn];
	 inline void add(int x,ll k){ while(x<=n) tree[x]+=k,x+=x&(-x); }
	 inline ll query(int x){ ll ret=0; while(x) ret+=tree[x],x-=x&(-x); return ret; }
}T;
struct NODE
{
	 int l,r;
	 mutable int col;
	 NODE(int L,int R=-1,int Col=0):l(L),r(R),col(Col){}
//	 bool operator < (const NODE &o) const { return l<o.l; }
	 bool friend operator < (NODE x,NODE y) { return x.l<y.l; }
};
set<NODE> s;
inline auto split(int p)
{
	 auto it=s.lower_bound(NODE(p));
	 if(it!=s.end() && it->l==p) return it;
	 it--;
	 int l=it->l,r=it->r,c=it->col;
	 s.erase(it);
	 s.insert(NODE(l,p-1,c));
	 return s.insert(NODE(p,r,c)).fi;
}
inline void merge(int l,int r,int c)
{
	 auto itr=split(r+1),itl=split(l);
	 for(auto it=itl;it!=itr;it++)
	 {
	 	 int L=it->l,R=it->r,Col=it->col;
	 	 T.add(L,addcol[Col]),T.add(R+1,-addcol[Col]);
	 }
	 s.erase(itl,itr);
	 s.insert(NODE(l,r,c));
	 T.add(l,-addcol[c]),T.add(r+1,addcol[c]);
}
inline int Color(int p)
{
	 auto it=s.lower_bound(NODE(p));
	 if(it!=s.end() && it->l==p) return it->col;
	 it--;
	 return it->col;
}
int main()
{
	 //ios::sync_with_stdio(false); cin.tie(0);
	 //freopen(".in","r",stdin);
	 //freopen(".out","w",stdout);
	 n=rd(),q=rd();
	 s.insert(NODE(1,n+1,1));
	 char opt[5];
	 for(int i=1,l,r,c,x;i<=q;i++)
	 {
	 	 scanf("%s",opt);
	 	 if(opt[0]=='C') l=rd(),r=rd(),c=rd(),merge(l,r,c);
		 else if(opt[0]=='A') c=rd(),x=rd(),addcol[c]+=x;
		 else x=rd(),c=Color(x),printf("%lld\n",T.query(x)+addcol[c]);
	 }
	 //fclose(stdin);
	 //fclose(stdout);
	 return 0;
}