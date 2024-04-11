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

const ll MOD=1000000007;

ll dp[1010][2][1010];
ll sump[1010][2][1010];

ll add(ll x, ll y){
	ll res=x+y;
	if(res>=MOD)res-=MOD;
	return res;
}

ll sub(ll x, ll y){
	ll res=x-y;
	if(res<0)res+=MOD;
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n,k; cin>>n>>k;
		fore(i,0,k){
			//cout<<"k="<<i<<":\n";
			fore(b,0,2){
				//cout<<"b="<<b<<":\n";
				fore(j,0,n+1){
					//cout<<"j="<<j<<":";
					if(i==0)dp[i][b][j]=1;
					else{
						if(b){
							dp[i][b][j]=sub(sump[i-1][0][n+1],sump[i-1][0][j+1]);
						}else{
							dp[i][b][j]=sub(sump[i-1][1][j],sump[i-1][1][1]);
						}
						dp[i][b][j]=add(dp[i][b][j],1);
					}
					//cout<<dp[i][b][j]<<"\n";
				}
				sump[i][b][0]=0;
				fore(j,0,n+1)sump[i][b][j+1]=add(sump[i][b][j],dp[i][b][j]);
			}
		}
		cout<<dp[k-1][1][0]<<"\n";
	}
	
	return 0;
}