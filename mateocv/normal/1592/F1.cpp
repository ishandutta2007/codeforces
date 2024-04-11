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
	ll n,m; cin>>n>>m;
	ll t[n][m];
	fore(i,0,n){
		fore(j,0,m){
			char c; cin>>c;
			t[i][j]=(c=='B');
		}
	}
	fore(i,0,n){
		for(ll j=m-1;j>=1;j--){
			t[i][j]=(t[i][j]^t[i][j-1]);
		}
	}
	for(ll i=n-1;i>=1;i--){
		fore(j,0,m){
			t[i][j]=(t[i][j]^t[i-1][j]);
		}
	}
	ll res=0;
	fore(i,1,n){
		fore(j,1,m){
			if(t[i][j]){
				res++;
				t[i][0]^=1;
				t[0][j]^=1;
				t[0][0]^=1;
			}
		}
	}
	ll c=0;
	fore(i,1,n)c+=t[i][0];
	fore(j,1,m)c+=t[0][j];
	res+=c+((c&1)!=t[0][0]);
	if((c&1)!=t[0][0]){
		ll br=0;
		fore(i,1,n){
			fore(j,1,m){
				if(t[i][j]&&t[i][0]&&t[0][j]){
					br++;
				}
			}
		}
		if(br)res--;
	}
	cout<<res<<"\n";
	
	return 0;
}