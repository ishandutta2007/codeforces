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

ll n,r[3],d; 
ll a[1000006];

ll dp[1000006][2];

ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==n){
		if(y==0)return res=0;
		return res=min({r[0],r[1],r[2]})+2*d;
	}
	if(y==0){
		res=9e18;
		res=min(res,r[1]+f(x+1,1)+d);
		res=min(res,a[x]*min(r[0],r[2])+r[0]+f(x+1,1)+d);
		res=min(res,a[x]*min(r[0],r[2])+r[2]+f(x+1,0)+d);
	}else{
		res=9e18;
		res=min(res,r[1]+d+min({r[0],r[1],r[2]})+d+min({r[0],r[1],r[2]})+d+f(x+1,0));
		res=min(res,a[x]*min(r[0],r[2])+r[0]+d+min({r[0],r[1],r[2]})+d+min({r[0],r[1],r[2]})+d+f(x+1,0));
		res=min(res,a[x]*min(r[0],r[2])+r[2]+d+min({r[0],r[1],r[2]})+(x==n-1?d:2*d+f(x+1,0)));
	}
	//cout<<x<<" "<<y<<" "<<res<<endl;
	return res;
}

int main(){FIN;
	cin>>n;
	fore(k,0,3)cin>>r[k];
	cin>>d;
	fore(i,0,n)cin>>a[i];
	mset(dp,-1);
	cout<<f(0,0)-d;
	
	return 0;
}