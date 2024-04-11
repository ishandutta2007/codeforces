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
template<typename T>
T gcd(T a, T b)
{
    return b ? gcd(b, a % b) : a;
}

template<typename T>
T lcm(T a,T b)
{
    return  a / gcd(a,b) * b;
}

#define int long long
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    sort(all(a));
    if(n==1){
        vector<int> p;
        rep(i,m){
            cout << a[0] + b[i] << " ";
        }
        cout << "\n";
    }else{
        vector<int> p;
        rep(i,n-1){
            p.push_back(a[i+1]-a[i]);
        }
        ll g = 0;
        rep(i,n-1){
            if(p[i]==0)continue;
            g = gcd(g,p[i]);
        }
        ll s = a[0];
        rep(i,m){
            cout << gcd(g,s+b[i]) << " ";
        }
        cout << "\n";
    }
    return 0;
}