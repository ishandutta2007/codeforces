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
vector<bool> ok;
vector<int> c;
vector<int> sub;
int n;

void dfs(int id,int pre){
    for(auto x:g[id]){
        if(x==pre)continue;
        dfs(x,id);
        c[id] += c[x];
        sub[id] = max(sub[id],sub[x]);
    }
    c[id]++;
    if(c[id] <= n/2){
        sub[id] = c[id];
    }
}

void dfs2(int id,int pre,ll val,ll sm){
    pair<int,int> mx={val,-1},mx2={0,-2};
    int ss = 0;
    bool flag = 0;
    if(sm >n/2){
        ss++;
        if(sm-val <= n/2)flag = 1;
    }
    
    for(auto x:g[id]){
        if(x==pre)continue;
        if(c[x]>n/2){
            ss++;
            if(c[x]-sub[x] <= n/2)flag = 1;
        }
        if(mx.first < sub[x]){
            mx2 = mx;
            mx = {sub[x],x};
        }else if(mx2.first < sub[x]){
            mx2 = {sub[x],x};
        }
    }
    for(auto x:g[id]){
        if(x==pre)continue;
        ll pp = -1;
        if(n-c[x] <= n/2) pp = n-c[x];
        ll qq = -1;
        if(mx.second!=x){
            qq = mx.first;
        }else{
            qq = mx2.first;
        }

        dfs2(x,id,max({pp,qq,val}) ,n -c[x]);
    }

    if(ss==0){
        ok[id] = 1;
    }else{
        if(flag)ok[id]=1;
    }

}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    g.resize(n);
    ok.resize(n);
    c.resize(n);
    sub.resize(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,-1);
    dfs2(0,-1,0LL,0LL);
    rep(i,n){
        cout << ok[i] << " ";
    }
    cout << "\n";
    return 0;
}