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

int dp[1000010][7][7];
int cnt[1000010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    rep(i,n){
        int a;
        cin >> a;
        cnt[a]++;
    }
    Fill(dp,-inf);
    dp[0][0][0] =0;
    for(int i=0;i<m;i++){
        for(int j=0;j<7;j++){
            for(int k=0;k<7;k++){
                if(dp[i][j][k]!=-inf){
                    int c = cnt[i+1];
                    for(int z = 0;z<7;z++){
                        if(j<z||k<z||c<z)break;
                        int C = (c-z)/3;
                        chmax(dp[i+1][k-z][(c-z)%3],dp[i][j][k] + z + C); 
                        if(C>=1){
                            chmax(dp[i+1][k-z][(c-z)%3 + 3],dp[i][j][k] + z + C-1);
                            
                        }
                        if(C>=2&&(c-z)%3==0){
                            chmax(dp[i+1][k-z][(c-z)%3 + 6],dp[i][j][k] + z + C-2);
                        }
                    }
                }
            }
        }
    }
    int mx = 0;
    rep(j,7){
        rep(k,7){
            chmax(mx,dp[m][j][k]);
        }
    }
    cout << mx << endl;
    return 0;
}