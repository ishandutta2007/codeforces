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
int dp[100010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pair<int,int> > a;
    rep(i,n){
        int p,q;
        cin >> p >> q;
        a.push_back({p,q});
    }
    sort(a.begin(),a.end());
    dp[0] = 1;
    for(int i=1;i<n;i++){
        int k = lower_bound(all(a),MP(a[i].first-a[i].second,-inf))-a.begin(); 
        if(k==0){
            dp[i] = 1;
        }else{
            dp[i] = dp[k-1] + 1;
        }
    }
    int mx = 0;
    rep(i,n){
        chmax(mx,dp[i]);
    }
    cout << n-mx << "\n";
    return 0;
}