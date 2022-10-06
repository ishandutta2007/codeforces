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
int n,k;

ll dp[200010][6];
ll dp2[200010][6];
ll cnt[200010][6];
ll cnt2[200010][6];
vector<vector<int> > g;

void dfs(int id,int pre){
    for(auto x:g[id]){
        if(x!=pre){
            dfs(x,id);
            for(int i=0;i<k;i++){
                if(i==0){
                    cnt[id][0] += cnt[x][k-1];
                    dp[id][0] += dp[x][k-1];
                    if(k==1)dp[id][0] += cnt[x][0];
                }else{
                    cnt[id][i] += cnt[x][i-1];
                    dp[id][i] += dp[x][i-1];
                    if(i==1)dp[id][i] +=  cnt[x][0];
                }
            }
        }
    }
    cnt[id][0] += 1;
    return;
}
void dfs2(int id,int pre){
    if(id==0){
        rep(i,k){
            cnt2[id][i] = cnt[id][i];
            dp2[id][i] = dp[id][i]; 
        }
    }
    if(pre!=-1){
        for(int i=0;i<k;i++){
            cnt2[id][i] = cnt[id][i] + (cnt2[pre][(i-1+k)%k] - cnt[id][(i-2+2*k)%k]);
            
            dp2[id][i] = dp[id][i] + (dp2[pre][(i-1+k)%k] - dp[id][(i-2+2*k)%k]);
            if((i-1+k)%k==0){
                dp2[id][i] +=  (cnt2[pre][(i-1+k)%k] - cnt[id][(i-2+2*k)%k]);
            }
            if(k==1&&i==0){
                dp2[id][i] +=  - cnt[id][(i-2+2*k)%k];
            }else if(i==2%k){
                dp2[id][i] +=  - cnt[id][(i-2+2*k)%k];
            }
        }
    }
    for(auto x:g[id]){
        if(x!=pre)dfs2(x,id);
    }
}
int main(){
    cin >> n >> k;
    g.resize(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,-1);
    
    dfs2(0,-1);
    ll sm = 0;
    rep(i,n){
        rep(j,k){
            sm += dp2[i][j];
            // cerr << i << " " << j << " "  << dp2[i][j] << endl;
        }
    }
    sm /= 2;
    cout << sm << endl;
    return 0;
}