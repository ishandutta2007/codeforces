#include<bits/stdc++.h>
#define ls(p) p<<1
#define rs(p) p<<1|1
#define de(x) cout<<#x<<" = "<<x<<endl;
#define rep(i,a,b) for(int i = (a);i<=(b);++i)
#define endl '\n'
#define PI acos(-1.0)
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int maxn = 5e5+10;
const int INF = 2e9+10;
const int mod = 1e9+7;
 
int n;
int c[65];
ll a[maxn],ans;
ll q[65];
void run(){
	cin>>n;
	ans = 0;
	rep(i,0,60) c[i] = 0;
	
	rep(i,1,n){
		scanf("%lld",&a[i]);
		for(int j = 0;j<=60;++j)
			if(q[j] & a[i]) c[j]++;
	}
	rep(i,1,n){
		ll x = 0,y = 0;
		rep(k,0,60){
			if(q[k] & a[i])
				x += q[k]%mod*n%mod;
			else
				x += q[k]%mod*c[k]%mod;
			x %= mod;
		}
		rep(j,0,60){
			if(a[i] & q[j]){
				y += (ll)c[j] * (q[j]%mod)%mod;
				y%=mod;
			}
		}
		ans += x*y%mod;
		ans %=mod;
		
	}
	cout<<ans<<'\n';
}
 
int main(){
	q[1] = 1;
	rep(i,2,60) q[i] = q[i-1]<<1;
	int t; cin>>t;
	while(t--){
		run();
	}
	return 0;
}