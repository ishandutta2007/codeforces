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
		vector<ll> b(n+1,1);
		fore(i,0,n){
			b[i]=lcm(b[i],a[i]);
			b[i+1]=lcm(b[i+1],a[i]);
		}
		ll res=1;
		fore(i,0,n){
			if(gcd(b[i],b[i+1])!=a[i])res=0;
		}
		cout<<(res?"YES\n":"NO\n");
	}
	
	return 0;
}