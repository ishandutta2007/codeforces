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
    vector<ll> a(3);
    cin >> a[0] >> a[1] >> a[2];
    cout << "First" << endl;
    cout << "4000000000" << endl;
    int x;
    cin >> x;
    x--;
    a[x] += 4000000000LL;
    // cerr << a[0] << " " << a[1] << " " << a[2] << endl;
    ll P = 3*a[x] - a[0]-a[1]-a[2];
    cout << 3*a[x] - a[0]-a[1]-a[2] << endl;
    cin >> x;
    x--;
    a[x] += P;
    sort(all(a));
    // cerr << a[0] << " " << a[1] << " " << a[2] << endl;
    cout << a[1]-a[0] << endl;
    return 0;
}