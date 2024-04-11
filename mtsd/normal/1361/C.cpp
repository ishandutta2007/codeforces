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
int a[1000010];
vector<int> res;
int z[20];
set<int> g[(1<<20)+1000000];
int n;
void dfs(int id){
    for(auto x=g[id].begin();x!=g[id].end();){
        g[*x].erase(id);
        int k = *x;
        g[id].erase(k);
        dfs(k);
        x = g[id].lower_bound(k);
    }
    if(id<2*n)res.push_back(id);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    int ppp = 2;
    rep(i,20){
        z[i] = ppp-1;
        ppp*=2;
    }
    rep(i,n){
        int s,t;
        cin >> s >> t;
        a[i*2] = s;
        a[i*2+1] = t; 
    }
    int ans = -1;
    for(int k=19;k>=0;k--){
        int ss[(1<<20)+1000000]={};
        rep(i,n){
            ss[2*i]++;
            ss[2*i+1]++;
        }
        rep(i,2*n){
            ss[i]++;
            ss[2*n+(z[k]&a[i])]++;
        }
        bool fff = 0;
        rep(i,(1<<20)+1000000){
            if(ss[i]%2!=0)fff = 1;
        }
        if(fff)continue;
        rep(i,(1<<20)+1000000){
            g[i].clear();
        }
        rep(i,n){
            g[2*i].insert(2*i+1);
            g[2*i+1].insert(2*i);
        }
        rep(i,2*n){
            g[i].insert(2*n+(z[k]&a[i]));
            g[2*n+(z[k]&a[i])].insert(i);
        }
        dfs(0);
        // cerr << k << " " << res.size() << endl;
        if(res.size()==2*n+1){
            cout << k+1 << "\n";
            if(res[0]/2==res[1]/2){
                rep(i,2*n){
                    cout << res[i]+1 << " ";
                }
            }else{
                rep(i,2*n){
                    cout << res[i+1]+1 << " ";
                }
            }
            cout << "\n";
            return 0;
        }else{
            res.clear();
        }
    }
    cout << 0 << "\n";
    rep(i,2*n){
        cout << i+1 << " ";
    }
    cout << "\n";
    return 0;
}