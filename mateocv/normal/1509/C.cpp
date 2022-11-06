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

vector<ll> a;

ll dp[2020][2020];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==y)return res=0;
	res=a[y]-a[x]+min(f(x+1,y),f(x,y-1));
	return res;
}

int main(){FIN;
	ll n; cin>>n;
	a.resize(n);
	fore(i,0,n)cin>>a[i];
	sort(ALL(a));
	mset(dp,-1);
	cout<<f(0,n-1)<<"\n";
	
	return 0;
}