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
        int n,l;
        cin >> n >> l;
        vector<int> a(n+1);
        a[0] = 0;
        rep(i,n) cin >> a[i+1];
        a.push_back(l);
        long double ax = 1.0,ay = 1.0;
        int L = 0;
        int R = n+1;
        long double tx = 0.0,ty = 0.0;
        long double res = 0;
        while(1){
            if(R==L+1){
                long double diff = a[R]-a[L];
                if(tx >=ty){
                    diff -= ay*(tx-ty);
                    res = tx + diff/(ax+ay);
                }else{
                    diff -= ax*(ty-tx);
                    res = ty + diff/(ax+ay);
                }
                break;
            }else{
                if(tx + (long double)(a[L+1]-a[L])/ax >= ty + (long double)(a[R]-a[R-1])/ay){
                    ty +=  (long double)(a[R]-a[R-1])/ay; 
                    ay+=1.0;
                    R--;
                }else{
                    tx += (long double)(a[L+1]-a[L])/ax;
                    ax += 1.0;
                    L++;
                }
            }
        }
        cout << setprecision(20) << fixed <<  res << "\n";
    }
    return 0;
}