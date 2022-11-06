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

ll n;
ll a[200005];

ll dp[200005][2];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x>=n){
		return res=0;
	}
	if(y){
		res=min(f(x+1,y^1),f(x+2,y^1));
	}else{
		res=min(f(x+1,y^1)+a[x],f(x+2,y^1)+a[x]+(x+1<n?a[x+1]:0));
	}
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		cin>>n;
		fore(i,0,n)cin>>a[i];
		fore(i,0,n+2){
			fore(j,0,2)dp[i][j]=-1;
		}
		cout<<f(0,0)<<"\n";
	}
	
	return 0;
}