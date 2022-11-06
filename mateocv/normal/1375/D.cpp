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

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll a[n];
		fore(i,0,n)cin>>a[i];
		set<ll> st;
		vector<ll> rep;
		fore(i,0,n){
			if(!st.count(a[i]))st.insert(a[i]);
			else rep.pb(i);
		}
		vector<ll> res;
		while(SZ(rep)){
			set<ll> sm;
			fore(i,0,n)sm.insert(a[i]);
			ll mex=-1;
			fore(i,0,n+1){
				if(!sm.count(i)){
					mex=i;
					break;
				}
			}
			res.pb(rep.back());
			a[rep.back()]=mex;
			rep.pop_back();
		}
		ll ok[n];
		ll tot=0;
		mset(ok,0);
		fore(i,0,n)ok[i]+=(a[i]==i),tot+=(a[i]==i);
		set<ll> sm;
		fore(i,0,n)sm.insert(a[i]);
		ll mex=-1;
		fore(i,0,n+1){
			if(!sm.count(i)){
				mex=i;
				break;
			}
		}
		while(tot<n){
			if(mex==n){
				fore(i,0,n){
					if(!ok[i]){
						swap(mex,a[i]);
						res.pb(i);
						break;
					}
				}
			}else{
				res.pb(mex);
				ok[mex]++;
				tot++;
				swap(mex,a[mex]);
			}
		}
		assert(SZ(res)<=2*n);
		cout<<SZ(res)<<"\n";
		for(auto i:res)cout<<i+1<<" ";
		cout<<"\n";
	}
	
	return 0;
}