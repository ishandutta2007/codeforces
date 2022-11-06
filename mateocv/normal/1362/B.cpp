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
		set<ll> st;
		fore(i,0,n){
			cin>>a[i];
			st.insert(a[i]);
		}
		ll br=0;
		fore(i,1,1025){
			set<ll> s;
			fore(j,0,n)s.insert(a[j]^i);
			if(s==st){
				cout<<i<<"\n";
				br++; break;
			}
		}
		if(br)continue;
		cout<<-1<<"\n";
	}
	
	return 0;
}