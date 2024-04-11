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
int testCases;
int n;

ll gcd(ll x, ll y) {return y==0?x:gcd(y,x%y);}
ll lcm(ll x, ll y) {return x*y/gcd(x,y);}

// find primes
bitset<MX> SIEVE;
vi primes;
void findPrimes() {
    SIEVE[0]=SIEVE[1]=1;
    REI(i,2,n) {
        if(SIEVE[i]) continue;
        primes.pb(i);
        for(int j=2*i; j<=n; j+=i) SIEVE[j] = 1;
    }
}

void program() {
    cin>>testCases;
    while(testCases--) {
        cin>>n;
        ii p = {1, n-1}; ll best = n+1;
        REP(i,2,sqrt(n)+3) {
            if(n % i != 0) continue;
            ll y=n/i;
            for(ll x=y; x<n; x+=y) {
                ll a=x, b=n-x;
                ll l = lcm(a, b);
                if(l < best) {
                    best = l;
                    p = {a,b};
                }
            }
        }
        cout<<p.fi<<" "<<p.se<<endl;
    }
}