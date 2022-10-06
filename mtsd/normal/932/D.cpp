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
#define inf (1LL<<60)
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
#define int long long
int p[400010][20];
int w[400010][20];
int sm[400010][20];
void add(int id,int P,int W){
    for(int k=19;k>=0;k--){
        if(w[P][k] < W){
            P = p[P][k];
        }
    }
    // cerr << "add ans:" << id << " " << P << endl;
    p[id][0] = P;
    w[id][0] = W;
    sm[id][0] = W;
    for(int k=1;k<20;k++){
        p[id][k] = p[p[id][k-1]][k-1];
        w[id][k] = w[p[id][k-1]][k-1];
        sm[id][k] = min(inf,sm[p[id][k-1]][k-1] + sm[id][k-1]);
    }
}

int calc(int id,int W){
    int res = 0;
    for(int k=19;k>=0;k--){
        if(sm[id][k]<=W){
            // cerr << id << " " << k << " " << W << " " << w[id][k] << endl;
            W -= sm[id][k];
            res += (1<<k);
            id = p[id][k];
        }
    }
    return res;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;
    int cnt = 1;
    rep(i,20){
        w[0][i] = inf;
        sm[0][i] = inf;
    }
    p[cnt][0] = 0;
    w[cnt][0] = 0;
    sm[cnt][0] = 0;
    rep(i,19){
        w[1][i+1] = inf;
        sm[1][i+1] = inf;
    }
    int last = 0;
    for(int i=0;i<Q;i++){
        int c,p,q;
        cin >> c >> p >> q;
        if(c==1){
            int R = p^last;
            int W = q^last;
            // cerr <<"add:" << R << " " << W << endl;
            cnt++;
            add(cnt,R,W);
        }else{
            int R = p^last;
            int W = q^last;
            // cerr << R << " " << W << endl;
            last = calc(R,W);
            cout << last << endl;
        }
    }
    return 0;
}