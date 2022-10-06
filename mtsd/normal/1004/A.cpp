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
    ll n,d;
    cin >> n >> d;
    vector<ll> v(n);
    rep(i,n)cin >> v[i];
    ll ans = 2;
    rep(i,n-1){
        if(v[i]+d >v[i+1]-d){
            continue;
        }else if(v[i]+d<v[i+1]-d){
            ans+=2;
        }else{
            ans+=1;
        }
    }
    cout << ans << endl;
    return 0;
}