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
    ll a,b,n;
    cin >> a >> b >> n;
    rep(zz,n){
        ll L,t,m;
        cin >> L >> t >> m;
        ll A = a + b*(L-1);
        ll B = b;
        ll ng = (t-A)/B +2;
        ll ok = 0;
        if(A>t||ng<=0){
            cout << -1 << "\n";
        }else{
            while(ng-ok>1){
                ll mid = (ok+ng)/2;
                if(m*t >= mid*(2*A+B*(mid-1))/2){
                    ok = mid;
                }else{
                    ng = mid;
                }
            }
            cout << L + ok-1 << "\n";
        }
    }
    return 0;
}