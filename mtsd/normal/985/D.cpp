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

ll calc(ll n){
    ll lo = 0;  
    ll up = (ll)1500000000;
    while(up-lo!=1){
        ll mid = (up+lo)/2;
        if(mid*(mid+1)<n*2){
            lo = mid;
        }else{
            up = mid;
        }
    }
    return up;
}
ll calc2(ll n,ll h){
    ll lo = h;  
    ll up = (ll)1500000000;
    while(up-lo!=1){
        ll mid = (up+lo)/2;
        if((mid+h-1)*(mid-h)/2+mid*(mid+1)/2<n){
            lo = mid;
        }else{
            up = mid;
        }
        //cout << mid << endl;
    }
    return up;
}

int main(){
    ll n,h;
    cin >> n >> h;
    ll x = calc(n);
    if(x<=h){
        cout << x << endl;
    }else{
        ll y = calc2(n,h);
        if((y+h-2)*(y-h-1)/2+(y-1)*(y)/2 + y > n){
            cout << 2*y-h-1 << endl;
        }else{
            cout << 2*y-h << endl;
        }
    }

    return 0;
}