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

const int MAXN=40004;

vector<ll> pal;

ll dp[505][MAXN];

ll f(ll x, ll y){
	if(y<0)return 0;
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==SZ(pal))return res=(y==0);
	res=(f(x+1,y)+f(x,y-pal[x]))%MOD;
	return res;
}

bool ispal(ll x){
	vector<ll> d;
	while(x){
		d.pb(x%10);
		x/=10;
	}
	auto dr=d;
	reverse(ALL(dr));
	return dr==d;
}

int main(){FIN;
	fore(i,1,MAXN)if(ispal(i))pal.pb(i);
	//cout<<SZ(pal)<<"\n";
	mset(dp,-1);
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		cout<<f(0,n)<<"\n";
	}
	
	return 0;
}