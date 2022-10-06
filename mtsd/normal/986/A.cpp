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
int res[100001][101];
int main(){
    Fill(res,10000000);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,k,s;
    cin >> n >> m >> k >> s;
    vector<vector<int> > p(k);
    rep(i,n){
        int a;
        cin >> a;
        a--;
        p[a].push_back(i);
    }
    vector<vector<int> > g(n);
    rep(i,m){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    rep(i,k){
        queue<pair<int,int> > q;
        for(auto x:p[i]){
            q.push(MP(x,0)); 
            res[x][i] = 0;
        }
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            int id = x.first;
            int c = x.second;
            for(auto y:g[id]){
                if(res[y][i]>c+1){
                    res[y][i] = c+1;
                    q.push(MP(y,c+1));
                }
            }
        }
    }
    rep(i,n){
        vector<int> ss;
        rep(j,k){
            ss.push_back(res[i][j]);
        }
        sort(ss.begin(),ss.end());
        int tmp = 0;
        rep(j,s){
            tmp += ss[j];
        }
        cout << tmp << " ";
    }
    cout << endl;
    return 0;
}