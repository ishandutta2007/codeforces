#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

long long  mod = 1000000007;

long long calc(long long  k,ll m){
	if(m==0)return 1;
	if(m==1)return k%mod;
	long long s = calc(k,m/2);
	if(m%2==0){
		return (s*s)%mod;
	}else{
		long long ans;
		ans = (s*s)%mod;
		return (k*ans)%mod;
	}
}

pair<ll,ll> pl(pair<ll,ll>p1,pair<ll,ll>p2){
	ll a,b;
	a = (p1.first*p2.second+p2.first*p1.second)%mod;
	b = (p1.second*p2.second)%mod;
	return MP(a,b);
}
pair<ll,ll> cr(pair<ll,ll>p1,pair<ll,ll>p2){
	ll a,b;
	a = (p1.first*p2.first)%mod;
	b = (p1.second*p2.second)%mod;
	return MP(a,b);
}


pair<ll,ll> dp[2020][1010];

int main(){
	ll k,pa,pb;
	cin >> k >> pa >> pb;
	for(int i=0;i<1010;i++){
		dp[i][0] = MP(0,1);
	}
	for(int i=1;i<1010;i++){
		for(int j=i;j<2020;j++){
			dp[j][i] = pl(MP(j,1),MP(pa,pb));
		}
	}
	for(int i=1;i<=k;i++){
		for(int j=i-1;j>=0;j--){
			if(j==0){
				dp[j][i] = dp[j+1][i];
			}else{
				dp[j][i] = pl(cr(MP(pa,pa+pb),dp[j+1][i]),cr(MP(pb,pa+pb),pl(dp[j][i-j],MP(j,1))));
			}
		}
	}
	// for(int i=0;i<=k;i++){
	//  	for(int j=0;j<=k;j++){
	// 	cout << j << " " << i << " " <<  dp[j][i].first << " " << dp[j][i].second << endl;
	//  	}
	// }
	ll ans = dp[0][k].first * (calc(dp[0][k].second,mod-2))%mod;
	cout << ans << endl;
	return 0;
}