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
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define int long long


long long mod_pow(long long a,long long b,long long MOD)
{
    a %= MOD;
    long long res = 1;
    while(b){
        if(b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}


ll fac[300000];

signed main(){
    ll n,m;
    cin >> n >> m;
    fac[0] = 1;
    for(int i=1;i<=n;i++){
        fac[i] = fac[i-1] * i % m;
    }
    ll res = 0;
    for(int k=1;k<=n;k++){
        ll tmp = fac[k]*fac[n-k+1]%m;
        tmp *= (n-k+1);
        tmp %= m;
        res += tmp;
        res %= m;
    }
    cout << res << endl;
    return 0;
}