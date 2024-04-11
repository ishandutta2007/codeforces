#include <iostream>
#include <iomanip>
#include <cstdio>

#include <cstring>
#include <string>
#include <sstream>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define mp make_pair

#define pb push_back
#define ff first
#define ss second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

//end of macro

bool isprime(ll x){
    if(x <= 1)return false;
    if(x%2 == 0)return false;
    for(ll i=3; i*i<=x; i+=2){
        if(x%i == 0)return false;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    ll a,b;
    cin>>a>>b;
    ll ans = 0;
    bool aprime = isprime(a);
    while(b){
        ll gcd = __gcd(a,b);
        if(gcd > 1){
            a /= gcd;
            b /= gcd;
            aprime = isprime(a);
        }

        if(a == 1){
            ans += b;
            break;
        }
        if(aprime){
            ll newb = (b/a)*a;
            ans += b-newb;
            b = newb;
        }else{
            b--;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}