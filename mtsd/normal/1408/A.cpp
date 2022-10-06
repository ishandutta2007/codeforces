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
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        vector<int> b(n);
        rep(i,n) cin >> b[i];
        vector<int> c(n);
        rep(i,n) cin >> c[i];
        vector<int> res(n);
        rep(i,n){
            if(i==0){
                res[i] = a[i];
            }else if(i!=n-1){
                if(res[i-1]!=a[i]){
                    res[i] = a[i];
                }else{
                    res[i] = b[i];
                }
            }else{
                if(res[0]!=a[i]&&res[i-1]!=a[i]){
                    res[i] = a[i];
                }else if(res[0]!=b[i]&&res[i-1]!=b[i]){
                    res[i] = b[i];
                }else{
                    res[i] = c[i];
                }
            }
        }
        rep(i,n){
            cout << res[i];
            if(i!=n-1)cout << " ";
        }
        cout << "\n";
    }
    return 0;
}