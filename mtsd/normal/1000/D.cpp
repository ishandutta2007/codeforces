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
ll mod = 998244353;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n) cin >> a[i];
    ll comb[1010][1010] = {};
    for(int i=0;i<1010;i++){
        comb[i][0] = 1;
        comb[i][i] = 1;
    }
    for(int i=2;i<1010;i++){
        for(int j=1;j<i;j++){
            comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%mod;
        }
    }
    ll dp[1010]={};
    dp[n] = 1;
    for(int i=n-1;i>=0;i--){
        if(a[i]<=0)continue;
        for(int m=i+a[i];m<n;m++){
            ll tmp = (comb[m-i][a[i]]*dp[m+1])%mod;
            dp[i] = (dp[i]+tmp)%mod;
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans = (ans+dp[i])%mod;
    }
    cout << ans << endl;
    return 0;
}