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
template< typename T >
int longest_increasing_subsequence(const vector< T > &a, bool strict) {
  vector< T > lis;
  for(auto &p : a) {
    typename vector< T >::iterator it;
    if(strict) it = lower_bound(all(lis), p);
    else it = upper_bound(all(lis), p);
    if(end(lis) == it) lis.emplace_back(p);
    else *it = p;
  }
  return lis.size();
}
vector<vector<int> > dp(101,vector<int>(101));
vector<vector<int> > calc(vector<vector<int> >&p,int k){
    if(k==1){
        return dp;
    }else if(k%2==0){
        auto tmp = calc(p,k/2);
        vector<vector<int>>res(101,vector<int>(101));
        rep(i,101){
            rep(j,101){
                for(int k = i;k<=j;k++){
                    chmax(res[i][j],tmp[i][k]+tmp[k][j]);
                }
            }
        }
        return res;
    }else{
        auto tmp = calc(p,k/2);
        vector<vector<int>>ress(101,vector<int>(101));
        rep(i,101){
            rep(j,101){
                for(int k = i;k<=j;k++){
                   chmax(ress[i][j],tmp[i][k]+tmp[k][j]);
                }
            }
        }
        vector<vector<int>>res(101,vector<int>(101));
        rep(i,101){
            rep(j,101){
                for(int k = i;k<=j;k++){
                    chmax(res[i][j],ress[i][k]+dp[k][j]);
                }
            }
        }
        return res;
    }
}
signed main(){
    int n,t;
    cin >> n >> t;
    vector<int> a(n);
    map<int,int> mp;
    rep(i,n){
        cin >> a[i];
    }
    vector<int> b = a;
    sort(all(b));
    b.erase(unique(all(b)),b.end());
    rep(i,b.size()){
        mp[b[i]] = i;
    }
    rep(i,n){
        a[i] = mp[a[i]];
    }
    for(int i=0;i<=100;i++){
        for(int j=i;j<=100;j++){
            vector<int> b;
            rep(k,n){
                if(a[k]>=i&&a[k]<=j){
                    b.push_back(a[k]);
                }
            }
            dp[i][j] = longest_increasing_subsequence(b,false);
        }
    }
    auto res = calc(dp,t);
    int mx = 0;
    rep(i,101){
        rep(j,101){
            chmax(mx,res[i][j]);
        }
    }
    cout << mx << endl;
    return 0;
}