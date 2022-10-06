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

int dst[110][110];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        int n,k;
        cin >> n >> k;
        vector<int> a(n),b(n);
        rep(i,n){
            cin >> a[i] >> b[i];
        }
        rep(i,n){
            rep(j,n)dst[i][j] = inf;
        }
        rep(i,n)dst[i][i] = 0;
        rep(i,n){
            rep(j,n){
                if(abs(a[i]-a[j]) + abs(b[i]-b[j]) <= k){
                    if(i!=j)dst[i][j] = 1;
                }
            }
        }
        int mi = inf;
        rep(i,n){
            int ma = 0;
            rep(j,n){
                chmax(ma,dst[i][j]);
            }
            chmin(mi,ma);
        }
        if(mi==inf){
            cout << -1 << "\n";
        }else{
            cout << mi << "\n";
        }
    }
    return 0;
}