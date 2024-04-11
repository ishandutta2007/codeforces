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
int ppp[300001];
char c[300001];
string s;
vector<vector<int> > g;
int nxt[300001][26];
int sub[300001];
int res[300001];
int dfs2(int x,int y){ // yx
    int diff = 0;
    rep(i,26){
        if(nxt[x][i]!=-1){
            if(nxt[y][i]==-1){
                nxt[y][i] = nxt[x][i];
                diff += sub[nxt[x][i]];
            }else{
                diff += dfs2(nxt[x][i],nxt[y][i]);
            }
        }
    }
    sub[y] += diff;
    return diff;
}

void dfs(int id,int pre){
    for(auto x:g[id]){
        if(x==pre)continue;
        dfs(x,id);
        int ch = s[x] - 'a';
        if(nxt[id][ch]!=-1){
            int y =  nxt[id][ch];
            if(sub[y] < sub[x]){
                sub[id] -= sub[y];
                sub[id] += sub[x];
                swap(x,y);
            }
            sub[id] -= sub[y];
            dfs2(x, y);
            nxt[id][ch] = y; 
            sub[id] += sub[y];
        }else{
            nxt[id][ch] = x;
            sub[id] += sub[x];
        }
    }
    sub[id]++;
    res[id] = sub[id];
    return ;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    Fill(nxt,-1);
    rep(i,n){
        cin >> ppp[i];
    }
    cin >> s;
    g.resize(n);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0,-1);
    int mx = -1;
    rep(i,n){
        chmax(mx,ppp[i] + res[i]);
        // cerr << res[i] << endl;
    }
    int sss = 0;
    rep(i,n){
        if(mx==ppp[i]+res[i]){
            sss++;
        }
    }
    cout << mx << endl;
    cout << sss << endl;
    return 0;
}