#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MOD=1000000007;
ll n,k,d;
ll dp[110][110][2];

ll f(ll a, ll b, ll c){
	if(b<0)return f(0,0,c);
	if(a<0)return f(0,b,c);
	ll &r=dp[a][b][c];
	if(r>=0)return r;
	if(a>b){
		r=0; return 0;
	}
	if(a==0&&b==0&c==0){
		r=1; return r;
	}
	if(a<b){
		r=(f(a,b-1,c)+f(b,b,c))%MOD; return r;
	}
	if(c==1&&a<d){
		r=0; return r;
	}
	if(c)r=f(a-k,a-d,0)+f(a-d+1,a-1,1);
	else r=f(a-k,a-1,0);
	r%=MOD;
	return r;
}

int main(){FIN;
	cin>>n>>k>>d;
	mset(dp,-1);
	cout<<f(n,n,1)<<"\n";
	return 0;
}