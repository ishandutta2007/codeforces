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
int MX = 100001;
long double dp[200010];
long double dp2[200010];
long double tmp[200010];
int main(){
    int n,m;
    cin >> n >> m;
    if(m==1){
        cout << "1.000000000000" << endl;
        return 0;
    }
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    int sm = accumulate(all(a),0);
    
    dp[0] = 1.0;
    long double p = (long double)1.0/((long double)(m-1));
    rep(z,n){
        int ng = a[z];
        for(int i=0;i<MX;i++){
            dp2[i+1] += dp[i]*p;
            dp2[i+m+1] -= dp[i]*p;
            tmp[i+ng] += dp[i]*p;
        }
        rep(i,MX){
            dp2[i+1] += dp2[i];
            dp2[i] -= tmp[i];
        }
        rep(i,MX){
            tmp[i] = 0;
            dp[i] = dp2[i];
            dp2[i] = 0;
        }
    }
    long double res = 0;
    rep(i,sm){
        res += dp[i];
    }
    cout << fixed << setprecision(30) << res*(m-1)+1.0 << endl;
    return 0;
}