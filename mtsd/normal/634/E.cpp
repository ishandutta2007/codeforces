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
int n,k,cnt;
    
vector<vector<int> > g;
int ppp[200010];
int flag[200010];
int sub[200010];
int sbf[200010];
int und[200010];
int res[200010];
int dp[200010];
void init(int id,int pre){
    for(auto x:g[id]){
        if(x==pre)continue;
        init(x,id);
        sub[id] += sub[x];
        sbf[id] += sbf[x];
    }
    sub[id]++;
    int mxund = 0;
    for(auto x:g[id]){
        if(x==pre)continue;
        if(sub[x] == und[x]){
            und[id] += und[x];
        }else{
            chmax(mxund,und[x]);
        }
    }
    if(flag[id]==0){
        und[id] = 0;
        res[id] = 0;
    }else{
        sbf[id]++;
        und[id]++;
        und[id] += mxund;
        chmax(res[id],und[id]);
        if(n - sub[id] == (cnt - sbf[id])){
            chmax(res[id],und[id] + n-sub[id]);
        }
    }
}

void dfs(int id,int pre,int val){
    int tmp = 0;
    int mx = 0;
    int sec = 0;
    for(auto x:g[id]){
        if(x==pre)continue;
        if(sub[x] == und[x]){
            tmp += und[x];
        }else{
            if(und[x] > mx){
                sec = mx;
                mx  = und[x]; 
            }else if(und[x] > sec){
                sec = und[x];
            }
        }
    }
    if(flag[id]==1){
        chmax(dp[id],max(tmp + mx + 1,tmp + val + 1));
        if(val == n - sub[id]){
            chmax(dp[id],tmp + val + mx + 1);
            for(auto x:g[id]){
                if(x==pre)continue;
                if(sub[x] != und[x]){
                    if(und[x]==mx){
                        dfs(x,id,tmp+val+sec+1);
                    }else{
                        dfs(x,id, dp[id]);
                    }
                }
            }
        }else{
            for(auto x:g[id]){
                if(x==pre)continue;
                if(sub[x] != und[x]){
                    if(und[x]==mx){
                        if(dp[id] == tmp + mx + 1){
                            // if(id==7)cerr <<"test: " <<  tmp << " " << val << " " << sec << " " << x << " " << mx << endl;
                            dfs(x,id,max(tmp+val+1,tmp+sec+1));
                        }else{
                            dfs(x,id,dp[id]);
                        }
                    }else{
                        dfs(x,id, dp[id]);
                    }
                }
            }
        }
    }else{
        for(auto x:g[id]){
            if(x==pre)continue;
            dfs(x,id,0);
        }
    }
    
}

bool solve(int val){
    
    cnt = 0;
    rep(i,n){
        flag[i] = (ppp[i] >= val);
        if(flag[i])cnt++;
    }
    rep(i,n){
        sub[i] = 0;res[i] = 0;und[i] = 0;dp[i] = 0;sbf[i] = 0;
    }
    init(0,-1);
    dfs(0,-1,0);
    // cerr << endl;
    rep(i,n){
        // cerr << res[i] << " " << dp[i] << " " << cnt << " " << sbf[i] << endl;
        if(k <= res[i] || k <= dp[i]){
            return true;
        }
    }
    return false;
}


int main(){
    cin >> n >> k;
    g.resize(n);
    rep(i,n){   
        cin >> ppp[i];
    }
    rep(i,n-1){
        int qq,rr;
        cin >> qq >> rr;
        qq--;
        rr--;
        g[qq].push_back(rr);
        g[rr].push_back(qq);
    }
    int ok = 1000000;
    int ng = 0;
    // solve(683826);
    while(ok-ng > 1){
        int mid = (ok+ng)/2;
        if(solve(mid)){
            ng = mid;
        }else{
            ok = mid;
        }
    }
    cout << ng << endl;
    return 0;
}