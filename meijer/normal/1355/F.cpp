#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second
#define sz size()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

//===================//
//  Added libraries  //
//===================//

//===================//
//end added libraries//
//===================//

void program();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    program();
}


//===================//
//   begin program   //
//===================//

const int MX = 5e5;
ll testCases;
ll mnD;
ll asks;

ll ask(ll x) {
    asks++;
    cout<<"? "<<x<<endl;
    cout.flush();
    ll ret;
    cin>>ret;
    return ret;
}

// find primes
bitset<MX> SIEVE;
vll primes;
void findPrimes() {
    SIEVE[0]=SIEVE[1]=1;
    REI(i,2,1e5) {
        if(SIEVE[i]) continue;
        primes.pb(i);
        for(ll j=2*i; j<=1e5; j+=i) SIEVE[j] = 1;
    }
}
vll getFactors(ll x) {
    vll ans;
    for(ll i=2; i*i<=x; i++) {
        while(x%i == 0) {
            ans.pb(i);
            x /= i;
        }
    }
    if(x > 1) ans.pb(x);
    return ans;
}


void program() {
    cin>>testCases;
    findPrimes();
    while(testCases--) {
        mnD = 1;

        asks = 0; ll i=0;
        while(asks < 22) {
            ll cur = 1;
            while(cur < 1e13) {
                cur *= primes[i++];
            }
            vll fact = getFactors(ask(cur));
            for(ll x : fact) {
                if(asks < 22) {
                    cur = 1;
                    while(cur < 1e13) cur *= x;
                    vll fact2 = getFactors(ask(cur));
                    mnD *= (fact2.sz+1);
                } else {
                    mnD *= 2;
                }
            }
        }

        cout<<"! "<<max(mnD*2,mnD+7)<<endl;
        cout.flush();
    }
}