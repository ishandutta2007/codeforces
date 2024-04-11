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
		ll n,m; cin>>n>>m;
		ll a[n][m];
		fore(i,0,n){
			fore(j,0,m){
				cin>>a[i][j];
			}
		}
		ll res[n][m];
		fore(i,0,n){
			fore(j,0,m){
				if((i==0||i==n-1)&&(j==0||j==m-1)){
					res[i][j]=2;
				}else if((i==0||i==n-1)||(j==0||j==m-1)){
					res[i][j]=3;
				}else{
					res[i][j]=4;
				}
			}
		}
		ll br=0;
		fore(i,0,n){
			fore(j,0,m){
				if(a[i][j]>res[i][j]){
					cout<<"NO\n";
					br++; break;
				}
			}
			if(br)break;
		}
		if(br)continue;
		cout<<"YES\n";
		fore(i,0,n){
			fore(j,0,m){
				cout<<res[i][j]<<" ";
			}
			cout<<"\n";
		}
	}
	
	return 0;
}