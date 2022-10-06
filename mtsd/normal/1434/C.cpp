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

ll a,b,c,d;
ll calc(ll k){
    return a*k - b*d*k*(k-1)/2;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        cin >> a >> b >> c >> d;
        if(b*c < a){
            cout << -1 << "\n";
            continue;
        }
        if(d > c){
            cout << a << "\n";
            continue;
        }
        ll T = a/(b*d);
        // cerr << T << endl;
        ll ma = 0;
        rep(i,4){
            if(T+i > c)break;
            chmax(ma,calc(T+i));
        }
        cout << ma << "\n";
    }
    return 0;
}