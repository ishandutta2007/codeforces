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
#define X real()
#define Y imag() 
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef vector<int>VI;
const LL MOD=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }

typedef long long TYP;
typedef complex<TYP> P;
inline TYP operator^(P a, P b) { return real(a) * imag(b) - imag(a) * real(b); }//iloczyn wektorowy
inline TYP operator%(P a, P b) { return real(a) * real(b) + imag(a) * imag(b); }//iloczyn skalarny

// w prawo <=> skret < 0
inline TYP skret(P a, P b, P c) { return (b - a) ^ (c - a);}
inline bool lexi(P a,P b) { if (real(a) != real(b)) return real(a) < real(b); return imag(a) < imag(b); }

#define EPS 0
inline int sgn(TYP a){ if (a > EPS) return 1; if (a < EPS) return -1;return 0; }//UWAGA na EPS

inline bool inter(P p1, P p2, P q1, P q2){
	LL s1 = sgn(skret(p1, p2, q1)), s2=sgn(skret(p1, p2, q2)), t1 = sgn(skret(q1, q2, p1)), t2 = sgn(skret(q1, q2, p2));
	if (s1 * s2 > 0 || t1 * t2 > 0)return false;
	P a;
	if (!s1 && !s2){
		if (lexi(p2, p1)) swap(p1,p2);
		if (lexi(q2, q1)) swap(q1,q2);
		if (lexi(p2, q1) || lexi(q2, p1)) return false;
	}
	return true;
}

#define MAXN 207
int n;
P p[MAXN];
bool is[MAXN][MAXN];
LL dp[MAXN][MAXN];
LL area[MAXN], pref[MAXN], suf[MAXN], total;

LL sum(int l,int r) {
  return pref[r] - (l ? pref[l-1] : 0);
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n;
    REP(i,n) cin >> p[i].X >> p[i].Y;
    p[n] = p[0];
    //area
    REP(i,n) area[i] = (p[i]^p[i+1]);
    REP(i,n) pref[i] = area[i] + (i?pref[i-1]:0);
    total = pref[n-1];
//    FORD(i,n-1,0) suf[i] = area[i] + (i<n?suf[i+1]:0);
	//sol
    REP(i,n) REP(j,i) {
      bool ok = true;
      REP(k,n) if(k != i && k != j && inter(p[i],p[j],p[k],p[k])) {ok=false; break;}
      if(ok) REP(k,n) {
        int kk = (k+1)%n;
        if(i == k || i == kk || j == k || j == kk) continue;
        if(inter(p[i],p[j],p[k],p[kk])) {ok=false; break;}
      }
      if(ok && (i+1)%n != j && (j+1)%n != i) {
//        cout << "OK" << " " << (p[j]^p[i]) << " " << sum(j,i) << " " << pref[n-1] << "      " << p[i] << "-" << p[j] << endl;
        LL A = sum(j,i-1) + (p[i]^p[j]);
        LL B = total - sum(j,i-1) + (p[j]^p[i]);
        ok = (llabs(A)+llabs(B) == llabs(total));
      }
        is[i][j] = is[j][i] = ok;
//        if(ok) cout << "is " << p[i] << " " << p[j] << endl;
    }
    //
    REP(i,n) dp[i][i] = dp[i][(i+1)%n] = 1;
    FOR(l,2,n-1) {
      REP(i,n) {
        int j = (i+l)%n;
        for(int k=(i+1)%n; k != j; k=(k+1)%n) {
          if(is[i][k] && is[j][k]) {
            dp[i][j] += dp[i][k] * dp[k][j];
            dp[i][j] %= MOD;
          }
        }
//        if(dp[i][j]) cout << i << " " << j << " = " << dp[i][j] << endl;
      }
    }
	//out
    REP(i,n) assert(dp[i][(i+n-1)%n] == dp[0][n-1]);
    cout << dp[0][n-1] << endl;
	return 0;
}