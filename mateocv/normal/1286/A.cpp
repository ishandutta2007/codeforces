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

ll dp[105][105][105][3];

ll n;
ll a[105];
ll INF=1e18;

ll f(ll x, ll y, ll z,ll l){
	if(y<0||z<0)return INF;
	ll &r=dp[x][y][z][l];
	if(r>=0)return r;
	if(x==n){
		r=0; return r;
	}
	if(a[x]!=0){
		r=f(x+1,y,z,a[x]%2)+(a[x]%2!=l&&l!=2); return r;
	}
	r=min(f(x+1,y-1,z,0)+(l==1),f(x+1,y,z-1,1)+(l==0)); return r;
}

int main(){FIN;
	cin>>n;
	fore(i,0,n)cin>>a[i];
	ll e=n/2,o=(n+1)/2;
	fore(i,0,n){
		if(a[i]!=0){
			if(a[i]%2==0)e--;
			else o--;
		}
	}
	mset(dp,-1);
	cout<<f(0,e,o,2);
	
	return 0;
}