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
    ll n;
    cin >> n;
    vector<ll> a(10,1);
    while(1){
        ll s = 1;
        rep(i,10){
            s *= a[i];
        }    
        if(s>=n)break;
        ll mi = 100000000;
        int id = 0;
        rep(i,10){
            if(chmin(mi,a[i])){
                id = i;
            }
        }
        a[id]++;
    }
    string t = "codeforces";
    string res;
    rep(i,10){
        rep(j,a[i]){
            res.push_back(t[i]);
        }
    }
    cout << res << "\n";
    return 0;
}