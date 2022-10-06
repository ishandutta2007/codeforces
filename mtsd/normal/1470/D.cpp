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
vector<vector<int> > g;
vector<int> res;
vector<bool> ok;
void dfs(int id,int pre){
    bool flag =0;
    ok[id] = 1;
    for(auto x:g[id]){
        if(res[x]){
            flag =1;
            break;
        }
    }
    if(!flag){
        res[id] = 1;
    }
    for(auto x:g[id]){
        if(x!=pre&&!ok[x]){
            dfs(x,id);
        }
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        int n,m;
        cin >> n >> m;
        g.resize(n);
        res.resize(n,0);
        ok.resize(n,0);
        rep(i,m){
            int a,b;
            cin >> a >> b;
            a--;b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }   
        dfs(0,-1);
        bool ng = 0;
        vector<int> ans;
        rep(i,n){
            if(!ok[i]){
                ng = 1;
            }else{
                if(res[i]==1)ans.push_back(i+1);
            }
        }
        if(ng){
            cout << "NO\n";    
        }else{
            cout << "YES\n";
            cout << ans.size() << "\n";
            rep(i,ans.size()){
                cout << ans[i] << " ";
            }
            cout << "\n";
        }
        g.clear();
        res.clear();
        ok.clear();
    }
    return 0;
}