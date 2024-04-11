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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,l,e,v;
    cin >> n >> m >> l >> e >> v;
    vector<int> L(l),E(e);
    rep(i,l)cin >> L[i];
    rep(i,e)cin >> E[i];
    int q;
    cin >> q;
    rep(zz,q){
        int x[2][2];
        rep(i,2)rep(j,2)cin >> x[i][j];
        if(x[0][0]==x[1][0]){
            cout << abs(x[0][1]-x[1][1]) << "\n";
            continue;
        }
        int mi = inf;
        int k;
        // left stair
        auto xx = upper_bound(all(L),x[0][1]);
        if(xx!=L.begin()){
            xx--;
            int k = *xx;
            chmin(mi, abs(x[0][1]-k) + abs(x[0][0]-x[1][0]) + abs(x[1][1]-k) );
        }
        // right stair
        xx = lower_bound(all(L),x[0][1]);
        if(xx!=L.end()){
            int k = *xx;
            chmin(mi, abs(x[0][1]-k) + abs(x[0][0]-x[1][0]) + abs(x[1][1]-k) );
        }

        xx = upper_bound(all(E),x[0][1]);
        if(xx!=E.begin()){
            xx--;
            int k = *xx;
            chmin(mi, abs(x[0][1]-k) + (abs(x[0][0]-x[1][0])+v-1)/v + abs(x[1][1]-k) );
        }
        xx = lower_bound(all(E),x[0][1]);
        if(xx!=E.end()){
            int k = *xx;
            chmin(mi, abs(x[0][1]-k) + (abs(x[0][0]-x[1][0])+v-1)/v + abs(x[1][1]-k) );
        }
        cout << mi << "\n";
    }
    return 0;
}