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

bool dp[102][102][10004];

int main(){FIN;
	fore(i,0,100){
		fore(j,0,100){
			fore(k,0,10001){
				if(i==0&&j==0){
					dp[i][j][k]=(k==0);
				}else{
					if(i-1>=0&&k-j-1>=0)dp[i][j][k]=(dp[i][j][k]||dp[i-1][j][k-j-1]);
					if(j-1>=0&&k-i-1>=0)dp[i][j][k]=(dp[i][j][k]||dp[i][j-1][k-i-1]);
				}
			}
		}
	}
	ll t; cin>>t;
	while(t--){
		ll n,m,k; cin>>n>>m>>k; n--; m--;
		if(dp[n][m][k])cout<<"YES\n";
		else cout<<"NO\n";
	}
	
	return 0;
}