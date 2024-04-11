#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(short i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const int MAXN=5055;

short dp0[MAXN][MAXN][2];

short dp1[MAXN][MAXN][2];

short INF=15000;

string s,t;

int main(){FIN;
	ll tt; cin>>tt;
	while(tt--){
		ll n,m; cin>>n>>m;
		cin>>s>>t;
		//cout<<"dp0\n";
		for(ll i=n;i>=0;i--){
			for(ll j=m;j>=0;j--){
				fore(k,0,2){
					short &res=dp0[i][j][k];
					if(j==m)res=(n-i);
					else if(i==n)res=INF;
					else{
						res=dp0[i+1][j][1]+1;
						if(s[i]==t[j])res=min(res,short(dp0[i+1][j+1][k]+k));
					}
					//cout<<i<<" "<<j<<" "<<k<<" "<<res<<"\n";
				}
			}
		}
		//cout<<"dp1\n";
		fore(i,0,n+1){
			fore(j,0,m+1){
				fore(k,0,2){
					short &res=dp1[i][j][k];
					if(j==0)res=2*i;
					else if(i==0)res=INF;
					else{
						res=dp1[i-1][j][1]+2;
						if(s[i-1]==t[j-1])res=min(res,short(dp1[i-1][j-1][k]+k));
					}
					//cout<<i<<" "<<j<<" "<<k<<" "<<res<<"\n";
				}
			}
		}
		ll res=dp0[0][0][0];
		fore(i,0,n+1){
			fore(j,0,m+1){
				if(dp0[i][j][0]>=INF||dp1[i][j][0]>=INF)continue;
				res=min(res,ll(dp0[i][j][0])+ll(dp1[i][j][0]+1));
			}
		}
		if(res>=INF)cout<<"-1\n";
		else cout<<res<<"\n";
	}
	
	return 0;
}