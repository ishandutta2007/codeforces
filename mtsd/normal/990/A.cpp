#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>

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
    ll n,m,a,b;
    cin >> n >> m >> a >> b;
    if(n%m==0){
        cout << 0 << endl;
        return 0;
    }
    ll x,y;
    x = (n/m+1)*m;
    y = (n/m)*m;
    ll ans = min((x-n)*a,(n-y)*b);
    cout << ans << endl;
    return 0;
}