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
    ll t;
    cin >> t;
    rep(zz,t){
        ll x,y,p,q;
        cin >> x >> y >> p >> q;
        ll ok = 2000000000;
        ll ng = 0;
        while(ok-ng>1){
            ll mid = (ok+ng)/2;
            if(mid*q>=y&&mid*p>=x&&mid*q-y>=mid*p-x){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        if(ok==2000000000){
            cout << -1 << endl;
        }else{
            cout << (q)*ok- y << endl;
        }
    }
    return 0;
}