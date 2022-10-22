#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
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

const int MX = 5e5, MX2=1e7+10;
int n, a[MX];
int A[MX], B[MX];

// find primes
bitset<MX2> SIEVE;
vi primes;
int minDiv[MX2];
void findPrimes() {
    SIEVE[0]=SIEVE[1]=1;
    REI(i,2,MX2-1) {
        if(SIEVE[i]) continue;
        primes.pb(i);
        minDiv[i] = i;
        for(int j=2*i; j<MX2; j+=i) if(!SIEVE[j]) {
            SIEVE[j] = 1;
            minDiv[j] = i;
        }
    }
}
int gcd(int a, int b) {return b==0?a:gcd(b,a%b);}


void program() {
    cin>>n;
    RE(i,n) cin>>a[i];
    RE(i,n) A[i]=B[i]=-1;
    findPrimes();
    RE(i,n) {
        int f = minDiv[a[i]];
        if(f == a[i]/f) continue;
        if(a[i]/f == 1) continue;
        A[i] = f;
        B[i] = a[i]/f;
        int g = A[i];
        while(B[i] % g == 0) {
            B[i] /= g;
        }
        if(B[i] == 1) {
            A[i] = -1;
            B[i] = -1;
        }
    }
    RE(_pi,n) cout<<(_pi==0?"":" ")<<A[_pi]; cout<<endl;
    RE(_pi,n) cout<<(_pi==0?"":" ")<<B[_pi]; cout<<endl;
}