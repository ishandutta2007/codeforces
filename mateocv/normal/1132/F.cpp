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

ll dp[505][505][2];

char a[505];

ll f(ll x, ll y, ll b){
	ll &r=dp[x][y][b];
	if(r>=0)return r;
	fore(i,x,y){
		if(a[i]!=a[x])break;
		if(i==y-1){
			r=0; 
			//cout<<x<<" "<<y<<" "<<b<<" -> "<<r<<"\n";
			return 0;
		}
	}
	r=1e18;
	if(b){
		fore(i,x+1,y){
			r=min({r,f(x,i,0)+f(i,y,1)+(a[x]!=a[y-1]),f(x,i,1)+f(i,y,1)+(a[i-1]!=a[y-1])});
		}
	}else{
		fore(i,x+1,y){
			r=min({r,f(x,i,0)+f(i,y,0)+(a[x]!=a[i]),f(x,i,0)+f(i,y,1)+(a[x]!=a[y-1])});
		}
	}
	//cout<<x<<" "<<y<<" "<<b<<" -> "<<r<<"\n";
	return r;
}

int main(){FIN;
	ll n; cin>>n;
	fore(i,0,n)cin>>a[i];
	mset(dp,-1);
	//cout<<f(0,n,0)<<" "<<f(0,n,1)<<"\n";
	cout<<min(f(0,n,0),f(0,n,1))+1;
	return 0;
}