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
 
ll solve(vector<ll> &v){
	ll res=0,va=0;
	fore(i,0,SZ(v)){
		va=max(v[i],v[i]+va);
		res=max(res,va);
	}
	return res;
}
 
vector<vector<ll>> v,vp;
 
void split(ll k){
	vector<ll> vv;
	for(auto i:v){
		for(auto j:i){
			vv.pb(j);
			if(j>=k){
				vv.pop_back();
				if(SZ(vv)!=0){
					vp.pb(vv);
				}
				vv.clear();
			}
		}
		vp.pb(vv);
		vv.clear();
	}
	v.clear();
	v=vp;
	vp.clear();
}
 
int main(){FIN;
	ll n; cin>>n;
	ll a[n];
	fore(i,0,n)cin>>a[i];
	vector<ll> vv;
	fore(i,0,n)vv.pb(a[i]);
	v.pb(vv);
	ll res=0;
	fore(i,0,31){
		for(auto &j:v)res=max(res,solve(j)-(30-i));
		split(30-i);
	}
	cout<<res;
	return 0;
}