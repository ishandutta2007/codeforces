#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

int main(){FIN;
	ll n,m; cin>>n>>m;
	ll a[n][m][2];
	fore(k,0,2){
		fore(i,0,n){
			fore(j,0,m){
				cin>>a[i][j][k];
			}
		}
	}
	fore(i,0,n){
		fore(j,0,m){
			ll maxi=max(a[i][j][0],a[i][j][1]);
			ll mini=a[i][j][0]+a[i][j][1]-maxi;
			a[i][j][0]=mini;
			a[i][j][1]=maxi;
		}
	}
	fore(k,0,2){
		fore(i,0,n){
			fore(j,0,m-1){
				if(a[i][j][k]>=a[i][j+1][k]){
					cout<<"Impossible"; return 0;
				}
			}
		}
	}
	fore(k,0,2){
		fore(i,0,n-1){
			fore(j,0,m){
				if(a[i][j][k]>=a[i+1][j][k]){
					cout<<"Impossible"; return 0;
				}
			}
		}
	}
	cout<<"Possible";
	return 0;
}