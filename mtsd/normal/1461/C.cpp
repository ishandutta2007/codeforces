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
    int t;
    cin >> t;
    rep(zz,t){
        int n,m;
        cin >> n >> m;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        int k = n;
        for(int i=n-1;i>=0;i--){
            if(a[i]!=i+1)break;
            k = i;
        }
       
        long double p = 1;
        rep(i,m){
            int a;
            long double b;
            cin >> a >> b;
            if(a>=k){
                p *= (1.0-b);
            }
        }
         if(k==0){
            cout << 1.0000000 << "\n";continue;
        }
        cout << setprecision(20) << fixed << (long double) 1.0 -p << "\n";
    }
    return 0;
}