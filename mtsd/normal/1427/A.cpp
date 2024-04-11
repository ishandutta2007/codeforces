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
        int sm = accumulate(a.begin(),a.end(),0);
        if(sm==0){
            cout << "NO\n";
            continue;
        }
        int pos = 0;
        int nega = 0;
        rep(i,n){
            if(a[i]>0){
                pos += a[i];
            }else{
                nega += -a[i];
            }
        }
        if(pos>nega){
            sort(a.rbegin(),a.rend());
        }else{
            sort(a.begin(),a.end());
        }
        cout << "YES\n";
        rep(i,n){
            cout << a[i];
            if(i!=n-1)cout << " ";
        }
        cout << "\n";
    }
    return 0;
}