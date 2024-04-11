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

bool dp[41][41][41][82];

ll tmo[1001][42];

int main(){FIN;
	fore(i,0,1001){
		fore(j,1,42){
			tmo[i][j]=i%j;
		}
	}
	ll t; cin>>t;
	while(t--){
		ll n,a,b; cin>>n>>a>>b;
		string s; cin>>s;
		mset(dp,0);
		for(ll x=n;x>=0;x--){
			fore(ra,0,a){
				fore(rb,0,b){
					fore(d,x,2*n+1-x){
						fore(k,0,2){
							bool &res=dp[x][ra][rb][d];
							if(x==n){
								res=(ra==0&&rb==0&&d==n);
							}else{
								res=0;
								res=(res||dp[x+1][tmo[10*ra+(s[x]-'0')][a]][rb][d+1]);
								res=(res||dp[x+1][ra][tmo[10*rb+(s[x]-'0')][b]][d-1]);
							}
						}
					}
				}
			}
		}
		ll d=-1;
		fore(i,0,n){
			if(dp[0][0][0][n+i]){
				d=n+i;
				break;
			}
			if(dp[0][0][0][n-i]){
				d=n-i;
				break;
			}
		}
		if(d==-1){
			cout<<"-1\n";
			continue;
		}
		ll x=0,ra=0,rb=0;
		string res;
		while(x<n){
			if(dp[x+1][tmo[10*ra+(s[x]-'0')][a]][rb][d+1]){
				res+='R';
				ra=(10*ra+(s[x]-'0'))%a;
				d++;
			}else{
				res+='B';
				rb=(10*rb+(s[x]-'0'))%b;
				d--;
			}
			x++;
		}
		cout<<res<<"\n";
	}
	
	return 0;
}