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
#include <stack>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
ll mod = 998244353;
#define rep(i,n) for(int i=0;i<(int)(n);++i)

ll p[1000010];
ll q[1000010];

int main(){
    ll n;
    cin >> n;
    vector<ll> a(n+2);
    for(ll i=0;i<=n;i++){
        if(i==0){
            q[i] = 1;
        }else{
            q[i] = q[i-1]*i%mod;
        }
    }
    for(ll i=0;i<=n;i++){
        if(i==0){
            p[i] = 1;
        }else{
            p[i] = p[i-1]*(n-i+1)%mod;
        }
    }
    rep(i,n-1){
        if(i==0){
            a[i] = p[n]-1;
        }else{
            ll tmp = (q[n-i]+mod-1)%mod;
            a[i] = p[i]*tmp;
        }
        //cerr << i << " " << a[i] << endl;
    }
    vector<ll> b(n+2);
    rep(i,n){
        if(i==0)continue;
        b[i] = (a[i]-a[i+1]+mod)%mod;
        //cerr <<i << " "<< b[i] << " " << endl;
    }
    ll ans = 0;
    for(ll i=1;i<=n-2;i++){
        ans += i*b[i];
        ans %= mod;
    }
    ans += p[n];
    ans %= mod;
    cout << ans << endl;
    return 0;
}