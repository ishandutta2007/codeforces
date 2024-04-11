#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[2][n][m];
	fore(k,0,2){
		fore(i,0,n){
			fore(j,0,m){
				cin>>a[k][i][j];
			}
		}
	}
	vector<ll> v[2][m+n-1];
	fore(k,0,2){
		fore(i,0,m+n-1){
			fore(j,0,i+1){
				if(j<n&&i-j>=0&&i-j<m){
					v[k][i].pb(a[k][j][i-j]);
				}
			}
		}
	}
	fore(k,0,2){
		fore(i,0,m+n-1){
			sort(ALL(v[k][i]));
		}
	}
	ll ok=0;
	fore(i,0,m+n-1){
		fore(j,0,SZ(v[0][i])){
			if(v[0][i][j]!=v[1][i][j]){
				ok--; break;
			}
		}
	}
	if(ok==0){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
	
	return 0;
}