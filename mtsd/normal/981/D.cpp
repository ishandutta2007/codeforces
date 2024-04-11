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
int n,k;
vector<ll> a;
vector<ll> s;

bool ok(ll x,ll ans){
    bool dp[53][53][53]={};
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(((s[j]-s[i]+a[i])&ans)==ans&&((s[j]-s[i]+a[i])&(1LL<<x))){
                dp[i][j][1] = 1;
                
            }
        }
    }
    for(int z=2;z<=k;z++){
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                for(int p=i;p<j;p++){
                    if(((s[p]-s[i]+a[i])&ans)==ans&&((s[p]-s[i]+a[i])&(1LL<<x))){
                        if(dp[p+1][j][z-1]){
                            dp[i][j][z] = 1;
                        }
                    }
                }
            }
        }
    }
    return dp[0][n-1][k];
}


int main(){
    cin >> n >> k;
    a.resize(n);
    s.resize(n);
    rep(i,n)cin >> a[i];
    s[0] = a[0];
    rep(i,n-1)s[i+1] = s[i]+a[i+1];
    ll ans = 0;
    for(ll i=57;i>=0;i--){
        if(ok(i,ans)){
            ans += (1LL<<i);
        }
    }
    cout << ans << endl;
    return 0;
}