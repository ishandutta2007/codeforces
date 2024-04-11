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
int dp[5010][2510][3];
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    Fill(dp,inf);
    dp[0][1][0] = 0;
    dp[0][0][2] = 0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n/2+3;j++){
            chmin(dp[i+1][j][1],dp[i][j][0] + max(0,a[i+1]-a[i]+1));
            chmin(dp[i+1][j][2],dp[i][j][1]);
            if(i>=1){
                if(a[i-1] > a[i]){
                    chmin(dp[i+1][j+1][0],dp[i][j][1] +  max(0,a[i]-a[i+1]+1));
                }else{
                    chmin(dp[i+1][j+1][0],dp[i][j][1] +  max(0,a[i-1]-1-a[i+1]+1));    
                }
                
            }
            chmin(dp[i+1][j][2],dp[i][j][2]);
            chmin(dp[i+1][j+1][0],dp[i][j][2] + max(0,a[i]-a[i+1]+1));
        }
    }
    rep(i,(n+1)/2){
        // cerr << dp[n-1][i+1][0] << " " << dp[n-1][i+1][1] << " " << dp[n-1][i+1][2] << endl;
        cout << min({dp[n-1][i+1][0],dp[n-1][i+1][1],dp[n-1][i+1][2]}) << " ";
    }
    cout << endl;
    return 0;
}