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

ll sumv[2][505];
ll sumh[2][505];

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
	fore(k,0,2){
		fore(i,0,n){
			fore(j,0,m){
				sumv[k][j]+=a[k][i][j];
				sumh[k][i]+=a[k][i][j];
			}
		}
	}
	fore(i,0,n){
		if((sumh[0][i]-sumh[1][i])%2){
			cout<<"No"; return 0;
		}
	}
	fore(i,0,m){
		if((sumv[0][i]-sumv[1][i])%2){
			cout<<"No"; return 0;
		}
	}
	cout<<"Yes";
	
	return 0;
}