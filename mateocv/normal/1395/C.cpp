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

ll n,m; 
ll a[202],b[202];

ll dp[202][520];

ll f(ll x, ll y){
	ll &r=dp[x][y];
	if(r>=0)return r;
	if(x==n)return r=1;
	r=0;
	fore(i,0,m){
		if(((a[x]&b[i])|y)==y){
			r=max(f(x+1,y),r);
		}
	}
	return r;
}

int main(){FIN;
	cin>>n>>m;
	fore(i,0,n)cin>>a[i];
	fore(i,0,m)cin>>b[i];
	mset(dp,-1);
	fore(i,0,(1<<9)){
		if(f(0,i)){
			cout<<i;
			return 0;
		}
	}
	
	return 0;
}