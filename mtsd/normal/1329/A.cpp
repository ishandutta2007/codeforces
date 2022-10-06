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
    int m,n;
    cin >> m >> n;
    vector<ll>a(n);
    rep(i,n){
        cin >> a[i];
    }
    vector<ll>res(n);
    ll sm = 0;
    bool flag = 0;
    rep(i,n){
        sm += a[i];
        if(a[i]>m-i){
            flag = 1;
        }
    }
    if(sm<m||flag){
        cout << -1 << "\n";
        return 0;
    }
    int p = m;
    for(int i=n-1;i>=0;i--){
        p = max((ll)i+1,p-a[i]+1);
        res[i] = p;
        p--;
    }
    rep(i,n){
        cout << res[i] << " ";
    }
    cout << "\n";
    return 0;
}