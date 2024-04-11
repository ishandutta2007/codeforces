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

vector<ll> dev;
vector<int> id;
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

void prime_factor(ll N){
	for(ll i=2;i*i<=N;i++){
		int cnt = 0;
		while(N%i == 0){
			cnt++;
			N /= i;
		}
		if(cnt){
			dev.push_back(i);
			id.push_back(cnt);
		}
	}
	if(N != 1){
		dev.push_back(N);
		id.push_back(1);
	}
	return;
}
ll dp[10010][60];
ll inv[60];
int main(){
    ll n;
    int k;
    cin >> n >> k;
    prime_factor(n);
    int m = id.size();
    ll ans = 1;
    rep(i,60){
        if(i!=0){
            inv[i] = calc((ll)i,mod-2);
        }
    }
    rep(tt,m){
        ll val = dev[tt];
        int s = id[tt];
        rep(i,k+1){
            rep(j,s+1){
                dp[i][j] = 0;
            }
        }
        dp[0][s] = 1LL;
        rep(i,k){
            rep(j,s+1){
                if(dp[i][j]!=0){
                    rep(x,j+1){
                        dp[i+1][x] += dp[i][j]*inv[j+1];
                        dp[i+1][x] %= mod;
                    }
                } 
            }
        }
        ll tmp = 0;
        rep(j,s+1){
            tmp += (dp[k][j] * calc(val,j)%mod);
            tmp %= mod;
        }
        ans *=tmp;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}