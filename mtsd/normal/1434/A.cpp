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
int table[6][100010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int m = 6;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i,n) cin >> b[i];
    sort(all(a));
    sort(all(b));
    priority_queue<pair<int,int> > pq;
    rep(i,m){
        rep(j,n){
            table[i][j] = b[j] - a[i];
        }
    }
    int mi = table[0][0];
    rep(j,n){
        pq.push({table[0][j],j});
    }
    vector<int> pp(n);
    int res = inf;
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        int id = x.second;
        int val = x.first;
        chmin(res,val-mi);
        if(pp[id]==m-1)break;
        pp[id]++;
        chmin(mi,table[pp[id]][id]);
        pq.push({table[pp[id]][id],id});
    }
    cout << res << endl;
    return 0;
}