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
int n;
vector<vector<int> > g;
vector<int> c;
vector<int> p;
bool ng;
int dfs(int id,int pre){
    int t = 0;
    for(auto x:g[id]){
        if(x!=pre){
            t += dfs(x,id);
        }
    }
    if(t==0&&p[id]){
        return 1;
    }
    if(t==1&&p[id]){
        return 1;
    }
    if(t==2){
        return 4;
    }
    if(t==3){
        ng = 1;
        return 4;
    }
    if(t>=5){
        ng = 1;
        return t;
    }
    if(t==4&&p[id]){
        ng = 1;
        return t;
    }
    return t;
}
int main(){
    cin >> n;
    g.resize(n);
    c.resize(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        c[a]++;
        c[b]++;
        g[a].push_back(b);
        g[b].push_back(a);   
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    rep(i,n){
        pq.push(MP(c[i],i));
    }
    vector<int> v(n);
    p.resize(n);
    vector<bool> flag(n);
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        if(c[x.second]!=x.first)continue;
        int id = x.second;
        if(p[id])continue;
        if(c[id]==1){
            if(v[id]<=1){
                for(auto y:g[id]){
                    if(flag[y])continue;
                    c[y]--;
                    pq.push(MP(c[y],y));
                    v[y]++;
                }
            }else if(v[id]==2){
                for(auto y:g[id]){
                    if(flag[y])continue;
                    c[y]--;
                    pq.push(MP(c[y],y));
                    
                    p[y] = 1;
                }
            }else{
                p[id] = 1;
            }
            flag[id] = 1;
        }
    }
    // rep(i,n){
    //     cerr << i << " " << p[i] << endl;
    // }
    dfs(0,-1);
    if(ng){
        cout << "No\n";
    }else{
        cout << "Yes\n";
    }
    return 0;
}