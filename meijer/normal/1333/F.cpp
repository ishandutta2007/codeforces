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

const int MX = 6e5;
int n;
// find primes
bitset<MX> SIEVE;
int f[MX];
void findPrimes() {
    SIEVE[0]=SIEVE[1]=1;
    REI(i,2,n) {
        if(SIEVE[i]) continue;
        f[i] = 1;
        for(int j=2*i; j<=n; j+=i) {
            if(!SIEVE[j]) f[j] = j/i;
            SIEVE[j] = 1;
        }
    }
}

void program() {
    cin>>n;
    findPrimes();
    sort(f+1, f+n+1);
    REI(i,2,n) {
        cout<<(i==2?"":" ")<<f[i];
    }
    cout<<endl;
}