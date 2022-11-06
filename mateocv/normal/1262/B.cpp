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
		fore(i,1,n+1){
			st.insert(i);
		}
		vector<ll> res;
		ll br=0;
		fore(i,0,n){
			if(st.count(a[i])){
				res.pb(a[i]);
				st.erase(a[i]);
			}else{
				ll s=*st.begin();
				res.pb(s);
				if(s>a[i]){
					br++; break;
				}
				st.erase(s);
			}
		}
		if(br){
			cout<<-1<<"\n";
		}else{
			for(auto i:res)cout<<i<<" "; cout<<"\n";
		}
	}
	
	return 0;
}