#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(ll i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

ll p[2],t[2];
ll h,s; 

const int MAXN=5050;

ll c[MAXN],pl[MAXN];

ll dp[MAXN][MAXN];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==h+1)return res=pl[y];
	res=pl[y];
	res=min(res,f(x+1,y));
	res=min(res,f(x,max(y-x,0ll))+c[x]);
	return res;
}

int main(){FIN;
	fore(k,0,2)cin>>p[k]>>t[k];
	cin>>h>>s;
	fore(i,0,MAXN)c[i]=2e18;
	fore(i,1,MAXN){
		fore(j,1,MAXN){
			auto ti=max(t[0]*i,t[1]*j);
			ll val=p[0]*i+p[1]*j-s*(i+j-1);
			auto d=min(h,val);
			c[d]=min(c[d],ti);
		}
	}
	fore(i,0,MAXN){
		ll l=0,r=2e18;
		while(l<=r){
			__int128 m=(l+r)/2;
			__int128 tp=(m/t[0])*(p[0]-s)+(m/t[1])*(p[1]-s);
			if(tp>=i)r=m-1;
			else l=m+1;
		}
		pl[i]=l;
	}
	mset(dp,-1);
	cout<<f(1,h)<<"\n";
	
	return 0;
}