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
vector<vector<int> > rev;
vector<int> dst;


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    g.resize(n);
    rev.resize(n);
    dst.resize(n,inf);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[b].push_back(a);
    }
    int k;
    cin >> k;
    vector<int> p(k);
    rep(i,k){
        cin >> p[i];
        p[i]--;
    }
    queue<int> q;
    q.push(p[k-1]);
    dst[p[k-1]] = 0;
    while(!q.empty()){
        int id = q.front();
        q.pop();
        for(auto x:g[id]){
            if(dst[x]<dst[id]+1)continue;
            if(dst[x]==inf){
                dst[x] = dst[id] + 1;
                rev[x].push_back(id);
                q.push(x);
            }else if(dst[x]==dst[id]+1){
                rev[x].push_back(id);
            }
        }
    }
    int mi = 0;
    int mx = 0;
    rep(i,k-1){
        bool flag = 0;
        for(auto x:rev[p[i]]){
            if(x == p[i+1])flag = 1;
        }
        if(!flag){
            mi++;
            mx++;
        }else{
            if(rev[p[i]].size()>1){
                mx++;
            }
        }
    }
    cout << mi << " " << mx << endl;
    return 0;
}