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
		vector<ll> v;
		fore(i,0,n){
			if(i>=2&&a[i]==a[i-2])continue;
			v.pb(a[i]);
		}
		set<ll> st;
		fore(i,0,SZ(v)){
			if((i>0&&v[i]==v[i-1])||(i>1&&v[i]==v[i-2])||(i>2&&v[i]==v[i-3]))v[i]++;
		}
		fore(i,0,SZ(v))st.insert(v[i]);
		cout<<SZ(st)<<"\n";
	}
	
	return 0;
}