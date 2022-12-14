#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL, LL>P;
typedef vector<int>VI;
const LL INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 100007

LL MOD = 1E9+7;

LL pot(LL a,LL n) {
    LL res = 1;
    while(n) {
        if(n%2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n /= 2;
    }
    return res;
}

LL p2[MAXN],p10[MAXN];
P operator+(P a,P b){return P((a.X+b.X)%MOD, (a.Y+b.Y)%MOD);}
LL mn(LL a,LL b){return (a*b)%MOD;}

void ust(P& p){
    p.X %= MOD;
    p.Y %= MOD;
    if(p.X < 0) p.X += MOD;
    if(p.Y < 0) p.Y += MOD;
}

P join(P p, LL val, LL licz) {
    //cout << "j " << p.X << "/" << p.Y << " " << val << " " << licz << endl;
    return P((p.X + 2 * val * licz)%MOD, (p.Y + mn(val,p.X) + mn(mn(val,val),licz))%MOD);
}

P full[MAXN], dp[MAXN], inter[MAXN];
LL inv9 = pot(9, MOD-2);
string l,r;

LL sol(string s) {
    int n = SZ(s);
    reverse(ALL(s));
    dp[1] = (s[0] == '4' ? P(0,0) : P(4 + 7, 4 * 7));  
    LL count = (s[0] == '7');
    FOR(i,2,n) {
        dp[i] = join(dp[i-1], mn(p10[i-1], s[i-1]-'0'), count);
        if(s[i-1] == '7') {
            dp[i] = dp[i] + join(full[i-1], mn(p10[i-1], 4), p2[i-1] - 1) + inter[i];
            count = (count + p2[i-1]) % MOD;
        }
        ust(dp[i]);
    }
    return dp[n].Y;
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> l >> r;
	//sol
    p2[0] = p10[0] = 1;
    FOR(i,1,MAXN-1) p2[i] = mn(p2[i-1], 2), p10[i] = mn(p10[i-1], 10);
    full[1] = P(4 + 7, 4 * 7);
    FOR(i,2,MAXN-1) {
        full[i] = join(full[i-1], mn(p10[i-1],4), p2[i-1] - 1);
        full[i] = full[i] + join(full[i-1], mn(p10[i-1],7), p2[i-1] - 1);
        inter[i].X += mn(mn((p10[i] - 1), inv9), (4 + 7));
        LL x = mn(p10[i-1] - 1, inv9);
        inter[i].Y += mn(x, p10[i-1]) * (4 * 4 + 7 * 7);
        inter[i].Y += mn(x, x) * 4 * 7;
        inter[i].Y += mn(p10[i-1], p10[i-1]) * 4 * 7;
        ust(inter[i]);
        full[i] = full[i] + inter[i];
        ust(full[i]);
    }
	//out
    //cout << sol(l) << endl << sol(r) << endl;
    LL res = sol(r) - sol(l);
    res %= MOD;
    if(res < 0) res += MOD;
    cout << res << endl;
	return 0;
}