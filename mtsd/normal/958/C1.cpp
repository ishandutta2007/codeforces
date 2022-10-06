#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}


int main(){
    ll n,p;
    cin >> n >> p;
    vector<ll>a(n);
    rep(i,n)cin >> a[i];
    ll s = 0;
    rep(i,n)s += a[i];
    ll t = 0;
    ll ans = 0;
    rep(i,n){
        t+= a[i];
        if(i==n-1)continue;
        ll z = s-t;
        ans = max(ans,t%p+z%p);
    }
    cout << ans << endl;
    return 0;
}