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
typedef long double ld;
int main(){
    int n,k;
    ld a,v1,v2;
    cin >> n >> a >> v1 >> v2 >> k;
    if(n<=k){
        cout << fixed << setprecision(20) <<  a/v2 << endl;
        return 0;
    }
    int c = (n+k-1)/k;
    ld r = c-1+(c-1)*(v2-v1)/(v1+v2);
    ld t1 = a/(v1+v2/r);
    ld t2 = t1/r;
    cerr << t1 << " " << t2 << endl;
    cout << fixed << setprecision(20) <<  t1+t2 << endl;
    return 0;
}