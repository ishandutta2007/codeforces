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
ll MOD=998244353;

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

const int MX = 3500;
string S, T;
int n, m;

mi cntLeft[MX][MX];// cntLeft[i][j] = amount of ways to make the first i characters of T, with the letters after from S after j
mi dp[MX][MX];
mi dp2[MX][MX];

mi getCntLeft(int i, int j) {
    if(i == 0) return n-j+1;
    if(j == n) return 0;
    if(cntLeft[i][j] != -1) return cntLeft[i][j];
    mi ans = 0;

    // throw away current letter
    ans += getCntLeft(i,j+1);

    // try to put this letter at the end
    if(T[i-1] == S[j]) ans += getCntLeft(i-1,j+1);

    return cntLeft[i][j] = ans;
}
mi getDP(int i, int j) {
    int k = j-i;
    if(j == m) return getCntLeft(i,k);
    if(k == n) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    mi ans = 0;
    char c = S[k];
    if(i != 0 && c == T[i-1]) {
        ans += getDP(i-1, j);
    }
    if(c == T[j]) {
        ans += getDP(i, j+1);
    }

    return dp[i][j] = ans;
}
mi getDP2(int i, int j) {
    if(i == 0) return n-j+1;
    if(j == n) return 0;
    if(dp2[i][j] != -1) return dp2[i][j];
    mi ans = 0;

    // throw away current letter
    ans += getDP2(i,j+1);
    if(i == m) ans *= ll(2);
    
    // try to put this letter at the end
    if(T[i-1] == S[j]) ans += getDP2(i-1,j+1);

    return dp2[i][j]= ans;
}

void program() {
    cin>>S>>T;
    n = S.size();
    m = T.size();
    RE(i,n+2) RE(j,n+2) cntLeft[i][j] = -1;
    RE(i,n+2) RE(j,n+2) dp[i][j] = -1;
    RE(i,n+2) RE(j,n+2) dp2[i][j] = -1;

    mi ans=0;
    RE(frontSize,m) {
        ans += getDP(frontSize,frontSize);
    }
    ans += getDP2(m,0);
    cout<<ans<<endl;
}