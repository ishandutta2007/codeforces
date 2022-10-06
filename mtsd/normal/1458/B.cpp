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

int a[101];
int b[101];
int dp[101][10001];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i,n)cin >> a[i] >> b[i];
    Fill(dp,-inf);
    int sm = 0;
    rep(i,n){
        sm += b[i];
    }
    dp[0][0] = 0;
    rep(i,n){
        for(int k = i;k>=0;k--){
            rep(j,100*(k+1) + 1){
                if(j+a[i]<=10000)chmax(dp[k+1][j+a[i]],dp[k][j] + b[i]);
            }
        }
    }
    int res = 0;
    for(int k=1;k<=n;k++){
        int mx = 0;
        rep(i,100*k+1){
            chmax(mx,min(2*i,dp[k][i]+sm));
        }
        res = max(mx,res);
        mx = res;
        if(mx%2==0){
            cout << mx/2 << " ";
        }else{
            cout << mx/2 << ".5 ";
        }
    }
    cout << "\n";
    return 0;
}