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

ll f[1000006][21];

int main(){FIN;
	ll t; cin>>t;
	mset(f,-1);
	while(t--){
		ll n,m; cin>>n>>m;
		char a[n][m];
		char b[n*m];
		fore(i,0,n){
			fore(j,0,m){
				cin>>b[m*i+j];
			}
		}
		string RDLU="RDLU";
		fore(i,0,n){
			fore(j,0,m){
				cin>>a[i][j];
				fore(ii,0,4){
					if(RDLU[ii]==a[i][j]){
						a[i][j]=ii; break;
					}
				}
			}
		}
		vector<ll> d={1,m,-1,-m};
		fore(i,0,n){
			fore(j,0,m){
				f[m*i+j][0]=m*i+j+d[a[i][j]];
			}
		}
		fore(j,1,21){
			fore(i,0,m*n){
				f[i][j]=f[f[i][j-1]][j-1];
			}
		}
	/*	fore(i,0,n*m){
			fore(j,0,21){
				cout<<f[i][j]<<" ";
			}
			cout<<"\n";
		}*/
		set<ll> st[2];
		fore(i,0,n*m){
			st[0].insert(f[i][20]);
			if(b[i]=='0')st[1].insert(f[i][20]);
		}
		cout<<SZ(st[0])<<" "<<SZ(st[1])<<"\n";
	//	for(auto i:st[0])cout<<i<<" "; cout<<"\n";
		fore(i,0,n*m){
			fore(j,0,21){
				f[i][j]=-1;
			}
		}
	}
	
	return 0;
}