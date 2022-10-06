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
const int MX = 18;
vector<vector<int> > g;
int parent[100010][MX];
int dep[100010];
vector<int>  st[100010][MX];
vector<int> merge(vector<int>&a,vector<int>&b){
    vector<int> tmp;
    sort(all(a));
    sort(all(b));
    int aid = 0;
    int bid = 0;
    while(tmp.size()<10){
        if(aid==a.size()){
            if(bid==b.size())break;
            tmp.push_back(b[bid]);
            bid++;
        }else{
            if(bid==b.size()){
                tmp.push_back(a[aid]);
                aid++;
                continue;
            }
            if(a[aid]==b[bid]){
                tmp.push_back(a[aid]);
                aid++;
                bid++;
            }else if(a[aid]<b[bid]){
                tmp.push_back(a[aid]);
                aid++;
            }else{
                tmp.push_back(b[bid]);
                bid++;    
            }
        }
    }
    return tmp;
}
void dfs(int id,int pre){
    if(pre!=-1){
        parent[id][0] = pre;
        dep[id] = dep[pre]+1;
    }
    for(auto x:g[id]){
        if(x==pre)continue;
        dfs(x,id);
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,q;
    cin >> n >> m >> q;
    g.resize(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,m){
        int a;
        cin >> a;
        if(st[a-1][0].size()<10)st[a-1][0].push_back(i+1);
    }
    dfs(0,-1);
    for(int j=1;j<MX;j++){
        rep(i,n){
            parent[i][j] = parent[parent[i][j-1]][j-1];
            st[i][j] = merge(st[i][j-1],st[parent[i][j-1]][j-1]);
        }
    }
    // cerr << "test" << endl;
    // for(auto x:st[4][2]){
    //     cerr << x << " " ;
    // }
    // cerr << endl;
    rep(zz,q){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        if(dep[a] < dep[b]) swap(a,b);
        vector<int> res;
        for(int i=0;i<MX;i++){
            if(((dep[a]-dep[b]) >> i)&1){
                res = merge(res,st[a][i]);
                a = parent[a][i];
            }
        }
        assert(dep[a]==dep[b]);
        if(a==b){
            res = merge(res,st[a][0]);
        }else{
            for(int i=MX-1;i>=0;i--){
                if(parent[a][i]!=parent[b][i]){
                    res = merge(res,st[a][i]);
                    res = merge(res,st[b][i]);
                    a = parent[a][i];
                    b = parent[b][i];
                }
            }
            res = merge(res,st[a][1]);
            res = merge(res,st[b][1]);
        }
        while((int)res.size() > c){
            res.pop_back();
        }
        cout << (int)res.size() << " ";
        for(auto x:res){
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}