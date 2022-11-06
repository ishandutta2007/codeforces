#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll solve(vector<ll> a, vector<ll> b){
	if(SZ(a)==0||SZ(b)==0)return 0;
	sort(ALL(a));
	sort(ALL(b));
	ll ac=0,res=0;
	auto br=b;
	reverse(ALL(br));
	fore(i,0,SZ(b)+1){
		if(i>0)ac+=(lower_bound(ALL(a),br[i-1]+1)-lower_bound(ALL(a),br[i-1]));
		ll ex=0;
		if(i<SZ(b)){
			ll ca=lower_bound(ALL(a),br[i]+1)-a.begin();
			ex=(lower_bound(ALL(b),br[i]+1)-lower_bound(ALL(b),br[i]+1-ca));
		}
		res=max(res,ac+ex);
	}
	return res;
}

pair<vector<ll>,vector<ll>> vp,vn;

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,m; cin>>n>>m;
		ll a[n],b[m];
		fore(i,0,n)cin>>a[i];
		fore(i,0,m)cin>>b[i];
		vp.fst.clear();
		vp.snd.clear();
		vn.fst.clear();
		vn.snd.clear();
		fore(i,0,n){
			if(a[i]>0)vp.fst.pb(a[i]);
			else vn.fst.pb(-a[i]);
		}
		fore(i,0,m){
			if(b[i]>0)vp.snd.pb(b[i]);
			else vn.snd.pb(-b[i]);
		}
		cout<<solve(vp.fst,vp.snd)+solve(vn.fst,vn.snd)<<"\n";
	}
	
	return 0;
}