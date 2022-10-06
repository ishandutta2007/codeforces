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
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    rep(tt,q){
        int n;
        cin >> n;
        vector<ll> a(n+1),b(n+1);
        a[0] = -inf;
        rep(i,n){
            cin >> a[i+1] >> b[i+1];
        }
        n++;
        vector<vector<ll> > dp(n+1,vector<ll>(10,1LL<<60));
        rep(i,10){
            dp[0][i] = 0;
        }
        for(int i=1;i<n;i++){
            rep(j,10){
                rep(k,10){
                    if(a[i]+j!=a[i-1]+k){
                        dp[i][j] = min(dp[i][j],dp[i-1][k]+b[i]*j);
                    }
                }
            }
        }
        ll mi = 1LL<<60;
        rep(i,10){
            mi = min(mi,dp[n-1][i]);
        }
        cout << mi << "\n";
    }
    return 0;
}