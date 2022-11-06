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
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		set<ll> st;
		fore(i,0,n)st.insert(i+1);
		vector<ll> b;
		for(auto i:a){
			if(st.count(i)){
				st.erase(i);
			}else b.pb(i);
		}
		sort(ALL(b));
		ll va=0,br=0;
		for(auto i:st){
			if((b[va]-1)/2<i)br++;
			va++;
		}
		if(br)cout<<"-1\n";
		else cout<<SZ(b)<<"\n";
	}
	
	return 0;
}