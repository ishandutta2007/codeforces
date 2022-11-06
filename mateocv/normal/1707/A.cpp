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
		ll n,q; cin>>n>>q;
		vector<ll> a(n);
		fore(i,0,n)cin>>a[i];
		reverse(ALL(a));
		ll va=0;
		string res;
		fore(i,0,n){
			if(a[i]<=va){
				res+='1';
			}else if(va<q){
				res+='1'; va++;
			}else res+='0';
		}
		reverse(ALL(res));
		cout<<res<<"\n";
	}
	
	return 0;
}