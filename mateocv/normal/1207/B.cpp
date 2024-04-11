#include <bits/stdc++.h>
#define pb push_back
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
	ll t[n][m];
	fore(i,0,n){
		fore(j,0,m){
			cin>>t[i][j];
		}
	}
	vector<pair<ll,ll>> res;
	fore(i,0,n){
		fore(j,0,m){
			if(t[i][j]){
				if(i>0&&j>0&&t[i-1][j-1]&&t[i][j-1]&&t[i-1][j]){
					res.pb({i,j});
				}else if(i<n-1&&j>0&&t[i+1][j-1]&&t[i][j-1]&&t[i+1][j]){
					res.pb({i+1,j});
				}else if(i>0&&j<m-1&&t[i-1][j+1]&&t[i][j+1]&&t[i-1][j]){
					res.pb({i,j+1});
				}else if(i<n-1&&j<m-1&&t[i+1][j+1]&&t[i][j+1]&&t[i+1][j]){
					res.pb({i+1,j+1});
				}else{
					cout<<-1; return 0;
				}
			}
		}
	}
	cout<<SZ(res)<<"\n";
	for(auto i:res)cout<<i.fst<<" "<<i.snd<<"\n";
	
	return 0;
}