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

vector<ll> a,b;

ll dp[102][20004];


ll f(ll x, ll y){
	ll &res=dp[x][y];
	if(res>=0)return res;
	if(x==SZ(a))return res=(y==0);
	res=0;
	if(a[x]<=y)res=(res||f(x+1,y-a[x]));
	if(b[x]<=y)res=(res||f(x+1,y-b[x]));
	return res;
}

int main(){FIN;
	ll t; cin>>t;
	while(t--){
		ll n; cin>>n;
		a.resize(n);
		b.resize(n);
		fore(i,0,n)cin>>a[i];
		fore(i,0,n)cin>>b[i];
		ll sa=0,sb=0,s=0;
		fore(i,0,n)sa+=a[i]*a[i],s+=a[i];
		fore(i,0,n)sb+=b[i]*b[i],s+=b[i];
		fore(i,0,n+1){
			fore(j,0,200*n+1){
				dp[i][j]=-1;
			}
		}
		ll res=1e18;
		fore(i,0,s+1){
			if(f(0,i))res=min(res,i*i+(s-i)*(s-i)+(n-2)*(sa+sb));
		}
		cout<<res<<"\n";
	}
	
	return 0;
}