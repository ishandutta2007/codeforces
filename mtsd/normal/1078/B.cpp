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
ll dp[3][101][10001];
ll comb[3][101][101];
ll mod[3] = {9999999999999937LL,1000000007,1000000000000037LL};
int main(){
    for(int i=0;i<3;i++){
        for(int j=0;j<=100;j++){
            comb[i][j][0] = 1;
            comb[i][j][j] = 1;
        }
        for(int j=0;j<=100;j++){
            for(int k=1;k<j;k++){
                comb[i][j][k] = comb[i][j-1][k-1] + comb[i][j-1][k];
                comb[i][j][k] %= mod[i];
            }
        }
    }
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n)cin >> a[i];
    sort(a.begin(),a.end());
    map<int,int> mp;
    rep(i,n)mp[a[i]]++;
    int ans = 0;
    rep(i,1){
        dp[i][0][0] = 1;
        rep(s,n){
            for(int j=n;j>=0;j--){
                rep(k,10000){
                    if(dp[i][j][k]!=0){
                        dp[i][j+1][k+a[s]] += dp[i][j][k];
                        dp[i][j+1][k+a[s]] %= mod[i];
                    }
                }
            }
        }
    }
    for(auto x:mp){
        int val = x.first;
        ll cnt = x.second;
        chmax(ans,1);
        for(int c=2;c<=cnt;c++){
            int V = val*c;
            bool flag = 1;
            rep(i,1){
                if(dp[i][c][V] != comb[i][cnt][c])flag = 0;
            }
            if(flag){
                chmax(ans,c);
            }
        }
    }
    if(mp.size()==2){
        if(mp[a[0]]==ans||mp[a[0]]==n-ans){
            ans = n;
        }
    }
    cout << ans << endl;
    return 0;
}