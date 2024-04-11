#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define mod  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define int long long 
long long calc(long long  k,long long m){
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

#define MAX_N 100005
#define MOD 1000000007

int inv[MAX_N],fac[MAX_N],finv[MAX_N];

void make()
{
	fac[0] = fac[1] = 1;
	finv[0] = finv[1] = 1;
	inv[1] = 1;
	for(int i=2;i<MAX_N;i++){
		inv[i] = MOD - (long long)inv[MOD%i] * (MOD/i) % MOD;
		fac[i] = (long long)fac[i-1] * i % MOD;
		finv[i] = (long long)finv[i-1] * inv[i] % MOD;
	}
}

int comb(int a,int b)
{
	if(a < b){
		return 0;
	}
	return fac[a] * ((long long)finv[b] * finv[a-b] % MOD) % MOD;
}

ll ss[100010];
signed main(){
    make();
    ll n,k;
    string s;
    cin >> n >> k >> s;
    if(k==0){
        ll ans = 0;
        for(ll i=0;i<n;i++){
            ans *= 10;
            ans %= mod;
            ans += s[i]- '0';
            ans %= mod;
        }
        cout << ans << endl;
        return 0;
    }
    for(ll i=0;i<n;i++){
        ss[i] = s[i]- '0';
    }
    for(int i=1;i<n;i++){
        ss[i] += ss[i-1];
        ss[i] %= mod;
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll tmp = 0;
        tmp += calc(10,i);
        tmp *= ss[n-2-i];
        tmp %= mod;
        tmp *= comb(n-2-i,k-1);
        tmp %= mod;
        ans += tmp;
        ans %= mod;
    }
    for(int i=0;i<n;i++){
        ans += ((s[n-1-i]-'0')*comb(n-1-i,k)%mod)*calc(10,i)%mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}