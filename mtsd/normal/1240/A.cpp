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
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    rep(zz,q){
        int n;
        cin >> n;
        vector<ll> p(n);
        rep(i,n)cin >> p[i];
        sort(p.begin(),p.end(),greater<ll>());
        ll x,a,y,b,k;
        cin >> x >> a >> y >> b >> k;
        if(x<y){
            swap(x,y);
            swap(a,b);
        }
        ll z = lcm(a,b);
        int ng = 0;
        int ok = n+1;
        while(ok-ng>1){
            int mid = (ok+ng)/2;
            ll s = mid/z;
            ll t = mid/a - s;
            ll u = mid/b - s;
            ll tmp = 0;
            for(int i=0;i<s;i++){
                tmp += p[i]/100*(x+y);
            }
            for(int i=s;i<s+t;i++){
                tmp += p[i]/100*x;
            }
            for(int i=s+t;i<s+t+u;i++){
                tmp += p[i]/100*y;
            }
            if(tmp>=k){
                ok = mid;
            }else{
                ng = mid;
            }
        }
        if(ng==n){
            cout << -1 << "\n";
        }else{
            cout << ok << "\n";
        }
    }
    return 0;
}