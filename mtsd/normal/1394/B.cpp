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
set<pair<int,int> > st[200010];
bool ng[10][10][10][10];
int res = 0;
int k;
void dfs(int id,vector<int>&a){
    if(id==k+1){
        bool flag = 0;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=i;j++){
                if(ng[i][a[i]][j][a[j]]){
                    flag = 1;
                    break;
                }
            }
            if(flag)break;
        }
        if(!flag){
            res++;
            // rep(i,k){
            //     cerr << a[i+1] << " ";
            // }
            // cerr << endl;
        }
        return;
    }
    for(int i=1;i<=id;i++){
        a[id] = i;
        dfs(id+1,a);
    }
    return;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m >> k;
    vector<vector<pair<int,int> > > g(n);
    rep(i,m){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        g[a].push_back(MP(c,b));
    }
    rep(i,n){
        sort(all(g[i]));
    }
    
    rep(i,n){
        int p = g[i].size();
        rep(j,g[i].size()){
            auto x = g[i][j];
            if(st[x.second].count(MP(p,j+1))){
                ng[p][j+1][p][j+1] = 1;
                // cerr << p << " " << j+1 << endl;
            }
            st[x.second].insert(MP(p,j+1));
        }
    }

    rep(i,n){
        vector<pair<int,int> > q;
        for(auto& x:st[i]){
            q.push_back(x);
        }
        rep(j,q.size()){
            rep(s,j){
                ng[q[j].first][q[j].second][q[s].first][q[s].second] = 1;
                ng[q[s].first][q[s].second][q[j].first][q[j].second] = 1;
                // cerr << q[j].first << " " << q[j].second << " " << q[s].first << " " << q[s].second << endl;
            }
        }
    }
    vector<int> pp(k+1);
    dfs(1,pp);
    cout << res << endl;
    return 0;
}