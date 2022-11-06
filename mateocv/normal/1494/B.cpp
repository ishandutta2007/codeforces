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

bool che(ll a, ll b, ll c, ll d, ll n){
	return (0<=a&&a<=n-2)&&(0<=b&&b<=n-2)&&(0<=c&&c<=n-2)&&(0<=d&&d<=n-2);
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		ll c[4];
		fore(i,0,4)cin>>c[i];
		ll br=0;
		fore(m,0,16){
			ll p[4];
			fore(i,0,4)p[i]=c[i];
			fore(i,0,4){
				if((1ll<<i)&m){
					p[i]--; p[(i+1)%4]--;
				}
			}
			if(che(p[0],p[1],p[2],p[3],n)){
				br++; break;
			}
		}
		if(br)cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}