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
		ll c[2][2];
		mset(c,0);
		fore(i,0,n){
			c[(i&1)][(a[i]&1)]++;
		}
		if((c[0][0]&&c[0][1])||(c[1][0]&&c[1][1]))cout<<"No\n";
		else cout<<"YEs\n";
	}
	
	return 0;
}