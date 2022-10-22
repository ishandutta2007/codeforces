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

// mod library
ll MOD=1e9+7;

inline ll mod(ll x_) {
	return (x_)%MOD;
}
ll modpow(ll x_, ll N_) {
    if(N_ == 0) return 1;
    ll a = modpow(x_,N_/2);
    a = (a*a)%MOD;
    if(N_%2) a = (a*x_)%MOD;
    return a;
}
ll inv(ll x_) {
    return modpow(x_, MOD-2);
}
class mi {
public:
    mi(ll v=0) {value = v;}
    mi  operator+ (ll rs) {return mod(value+rs);}
    mi  operator- (ll rs) {return mod(value-rs+MOD);}
    mi  operator* (ll rs) {return mod(value*rs);}
    mi  operator/ (ll rs) {return mod(value*inv(rs));}
    mi& operator+=(ll rs) {*this = (*this)+rs; return *this;}
    mi& operator-=(ll rs) {*this = (*this)-rs; return *this;}
    mi& operator*=(ll rs) {*this = (*this)*rs; return *this;}
    mi& operator/=(ll rs) {*this = (*this)/rs; return *this;}
    operator ll&() {return value;}

    ll value;
};
typedef vector<mi> vmi;

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

const int MX = 5e5, BIT=19, BM=(1<<BIT);
int n, a[MX];
bitset<71> isPrime;
vi primes;
int cnt[71], bm[71];
mi ways[71][2], dp[2][BM];

void program() {
    cin>>n;
    RE(i,n) cin>>a[i];
    REP(i,2,71) isPrime[i] = 1;
    REP(i,2,71) {
        if(!isPrime[i]) continue;
        primes.pb(i);
        for(int j=i*2; j<=70; j+=i) isPrime[j] = 0;
    }
    REP(i,1,71) {
        bm[i] = 0;
        int x = i;
        while(x != 1) {
            RE(j,primes.size()) {
                while(x % primes[j] == 0) {
                    x /= primes[j];
                    bm[i] ^= (1<<j);
                }
            }
        }
    }
    RE(i,71) cnt[i] = 0;
    RE(i,n) cnt[a[i]]++;
    REP(i,1,71) {
        ways[i][0] = ways[i][1] = 0;
        mi curWays = 1;
        mi curFact = 1;
        REP(j,0,cnt[i]+1) {
            ways[i][j%2] += curWays/curFact;
            curWays *= ll(cnt[i]-j);
            curFact *= ll(j+1);
        }
    }
    dp[0][0] = 1;
    REP(i,1,71) {
        RE(j,BM) {
            dp[i%2][j] = dp[(i+1)%2][j]*ways[i][0] + dp[(i+1)%2][j^bm[i]]*ways[i][1];
        }
    }
    cout<<dp[70%2][0]-ll(1)<<endl;
}