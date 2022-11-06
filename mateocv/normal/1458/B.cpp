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
typedef int ll;

vector<pair<ll,ll>> v;

int dp0[101][201*101];
int dp1[101][201*101];

ll INF=2e9;

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n){
		ll a,b; cin>>a>>b;
		v.pb({a,b});
	}
	fore(i,0,101){
		fore(j,0,201*101){
			dp0[i][j]=-INF;
		}
	}
	dp0[0][0]=0;
	for(ll i=n-1;i>=0;i--){
		fore(j,0,n+1){
			fore(k,0,20001){
				dp1[j][k]=dp0[j][k]+v[i].snd;
				if(j>0&&k-2*v[i].fst>=0)dp1[j][k]=max(dp1[j][k],dp0[j-1][k-2*v[i].fst]+2*v[i].snd);
			}
		}
		fore(j,0,n+1){
			fore(k,0,20001){
				dp0[j][k]=dp1[j][k];
			}
		}
	}
	cout<<fixed<<setprecision(10);
	fore(i,0,n){
		int res=-INF;
		fore(j,0,201*101)res=max(res,min(dp0[i+1][j],j));
		cout<<((long double)1)*res/2<<" ";
	}
	cout<<"\n";
	return 0;
}