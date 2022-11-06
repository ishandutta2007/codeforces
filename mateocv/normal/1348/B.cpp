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
		ll n,k; cin>>n>>k;
		set<ll> st;
		ll a[n];
		fore(i,0,n)cin>>a[i],st.insert(a[i]);
		vector<ll>v;
		for(auto i:st){
			v.pb(i);
		}
		if(SZ(st)>k){
			cout<<-1<<"\n";
		}else{
			cout<<n*k<<"\n";
			fore(i,0,n*k){
				if(i%k<SZ(st))cout<<v[i%k]<<" ";
				else{
					cout<<v[0]<<" ";
				}
			}
		}
		cout<<"\n";
	}
	
	return 0;
}