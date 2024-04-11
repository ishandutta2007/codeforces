#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}
#define int long long
int v[6], w[6], m[6];
int F[6];
int val[1000000];
int dp[1000010] = {};
int dp2[1000010] = {};
    
signed main(){
    int k;
    cin >> k;
    int n = 6;
    rep(i,n)cin >> F[i];
    int P = 1;
    rep(i,n){
        v[i] = F[i];
        w[i] = P*3;
        m[i] = 3*k;
        P *= 10;
    }
    rep(i,1000000){
        int vv = i;
        rep(j,6){
            int kk = vv%10;
            if(kk%3==0){
                val[i] += kk/3 * F[j];
            }
            vv /= 10;
        }
        
    }
    // cerr << val[39] << endl;
    ll INF = (1LL<<60);
    Fill(dp,-INF);
    dp[0] = 0;
    
    rep(i,n){
        m[i] = 3*(k-1);
    }
    rep(i,n) {
        // take key good(s) each
        for(int k=0; m[i]>0; k++) {
            int key = min(m[i], (int)(1<<k));
            m[i] -= key;
            for(int j=999999; j>=key*w[i]; j--) {
                // do not take or take
                dp[j] = max(dp[j], dp[j-key*w[i]] + key*v[i]);
            }
        }
    }
    rep(i,1000000){
        dp2[i] = dp[i];
    }
    P = 1;
    rep(k,6){
        rep(i,10){
            int W = P*i;
            int V = 0;
            if(i%3==0){
                V = i/3 * F[k];
            }
            for(int j=999999;j>=0;j--){
                if(j-W<0)break;
                chmax(dp2[j],dp[j-W] + V);
            }
        }
        rep(i,1000000){
            dp[i] = dp2[i];
        }
        P *= 10;
    }
    int q;
    cin >> q;
    rep(zz,q){
        int ww;
        cin >> ww;
        cout << dp2[ww] << "\n";        
    }    
    // cerr << ans << endl;
    return 0;
}