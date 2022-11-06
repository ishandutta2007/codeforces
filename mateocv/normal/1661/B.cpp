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

const int MAXN=32768;

ll dp[MAXN][20];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(y==0)return res=(x==0);
	res=max(f((x+1)%MAXN,y-1),f((x+x)%MAXN,y-1));
	return res;
}

int main(){FIN;
	mset(dp,-1);
	ll t; cin>>t;
	while(t--){
		ll x; cin>>x;
		fore(i,0,20){
			if(f(x,i)){
				cout<<i<<" ";
				break;
			}
		}
	}
	cout<<"\n";
	
	return 0;
}