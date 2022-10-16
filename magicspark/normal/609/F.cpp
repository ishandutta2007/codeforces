/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,m;
pair<int,pair<int,int> >dat[200005];
int x[200005],t[200005],rev[200005];
int p[200005],b[200005];
struct frog{
	int l,r,id,ans;
	frog(int L,int R,int Id,int Ans){l=L;r=R;id=Id;ans=Ans;}
};
bool operator<(frog F1,frog F2){
	if(F1.r!=F2.r)return F1.r<F2.r;
	return F1.l>F2.l;
}
set<frog>F;
multiset<pair<int,int> >M;
map<int,pair<int,int> >ans;
void solve(int p,int sz){
	auto itr=F.lower_bound(frog((int)1e18,p,0,0));
	if(itr==F.end()||itr->l>p){
		M.insert(make_pair(p,sz));
	}else{
		frog FF=*itr;F.erase(itr);
		FF.r+=sz;FF.ans++;
		auto itm=M.lower_bound(make_pair(FF.l,0));
		while(itm!=M.end()&&itm->first<=FF.r){
//			cerr<<itm->first<<" "<<itm->second<<endl;
			FF.r+=itm->second;FF.ans++;M.erase(itm++);
		}
		ans[FF.l]=make_pair(FF.r,FF.ans);
//		cerr<<"show:"<<FF.l<<" "<<FF.r<<" "<<FF.ans<<endl;
		F.insert(FF);auto iter=F.find(FF);
		while(iter!=F.begin()&&(prev(iter)->l)>=(iter->l)){
			F.erase(prev(iter));
		}
	}
}
signed main(){
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%I64d%I64d",&dat[i].first,&dat[i].second.first);
		x[i]=dat[i].first;t[i]=dat[i].second.first;
		dat[i].second.second=i;
	}
	sort(dat+1,dat+n+1);
	for(int i=1;i<=n;i++){
		rev[dat[i].second.second]=i;
//		cerr<<dat[i].first<<" "<<dat[i].first+dat[i].second.first<<endl;
		F.insert(frog(dat[i].first,dat[i].first+dat[i].second.first,i,0));
	}
	for(auto itr=F.rbegin();itr!=F.rend();itr++){
		while(next(itr)!=F.rend()&&itr->l<=next(itr)->l){
			F.erase(F.find(*next(itr)));
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%I64d%I64d",&p[i],&b[i]);
		solve(p[i],b[i]);
	}
	for(int i=1;i<=n;i++){
		if(ans.count(x[i]))cout<<ans[x[i]].second<<" "<<ans[x[i]].first-x[i]<<endl;
		else cout<<"0 "<<t[i]<<endl;
	}
	return 0;
}