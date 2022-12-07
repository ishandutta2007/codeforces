#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 1000010
#define MOD 1000000007
#define INF (ll)1e+18
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;

bool u[30];
ll k[N];
ll r[N];
ll p3[N];

void init(void){
	p3[0]=1;
	rep(i,N-1)p3[i+1]=(p3[i]*3)%MOD;
	k[0]=1;
	rep(i,N-1)k[i+1]=(k[i]*(i+1))%MOD;
	ll x=MOD-2;
	rep(i,30){
		if(x&1)u[i]=true;
		else u[i]=false;
		x=(x>>1);
	}
	rep(i,N){
		x=k[i];
		r[i]=1;
		rep(j,30){
			if(u[j])r[i]=(r[i]*x)%MOD;
			x=(x*x)%MOD;
		}
	}
	return;
}

ll nik(int a,int b){
	if((a<0)&&(b<0))return 1;
	if((a<0)||(b<0))return 0;
	ll ret=(k[a]*r[b])%MOD;
	ret=(ret*r[a-b])%MOD;
	return ret;
}

int main() {
	int n,k,a,b;
	ll ans=0;
	ll s;
	init();
  cin>>n>>k;
	if(k==0){
		cout<<p3[n]<<"\n";
		return 0;
	}
	rep(i,n+1){
		a=(i+3)/2;
		b=(i+2)/2;
		if((n-k+1)<a)break;
		if(k<b)break;
		s=(nik(n-k,a-1)*nik(k-1,b-1))%MOD;
		s=(s*p3[n+1-a-b])%MOD;
		ans=(ans+s)%MOD;
	}
	cout<<ans<<endl;
	return 0;
}