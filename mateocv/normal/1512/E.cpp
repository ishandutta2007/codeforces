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
		ll n,l,r,s; cin>>n>>l>>r>>s; l--;
		vector<ll> v;
		fore(i,0,r-l)v.pb(i+1),s-=i+1;
		reverse(ALL(v));
		if(s<0){
			cout<<"-1\n";
			continue;
		}
		ll cm=n-SZ(v);
		fore(i,0,SZ(v)){
			ll maxi=min(s,cm);
			v[i]+=maxi;
			s-=maxi;
		}
		if(s==0){
			set<ll> st;
			fore(i,0,n)st.insert(i+1);
			for(auto i:v)st.erase(i);
			fore(i,0,n){
				if(l<=i&&i<r){
					assert(SZ(v));
					cout<<v.back()<<" ";
					v.pop_back();
				}else{
					assert(SZ(st));
					ll b=*st.begin();
					cout<<b<<" ";
					st.erase(b);
				}
			}
			cout<<"\n";
		}else{
			cout<<"-1\n";
		}
	}
	
	return 0;
}