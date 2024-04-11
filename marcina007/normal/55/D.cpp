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
#include<bitset>
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
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 1000007

#define MOD (5*7*8*9)
#define MASKS (1<<8)

LL ile[MASKS][MOD], dobre[MASKS][MOD], dp[21][MOD];
VI sub[MASKS], reszty[MASKS];
int move[MOD][10];


void count(int mask, LL x) {
    VI ogr, opcje;
    while(x) {
        ogr.PB(x%10);
        x /= 10;
    }
    opcje.PB(0);
    opcje.PB(1);
    FOR(i,2,9) if(mask&(1<<(i-2)))
        opcje.PB(i);
    reverse(ALL(ogr));
    CLR(dp);
    REP(i,SZ(ogr)) {
            REP(r,MOD) {
                    if(dp[i][r])
                        FORE(o,opcje)
                            dp[i+1][move[r][*o]] += dp[i][r];
            }
            LL val = 0;
            bool ok = true;
            REP(j,i) {
                if(ogr[j] >= 2)
                    if(!(mask&(1<<(ogr[j]-2))))
                        ok = false;
                val=(val*10+ogr[j])%MOD;
            }
            if(ok)
                FORE(o,opcje) if(*o < ogr[i])
                    dp[i+1][move[val][*o]]++;
    }
    REP(i,MOD)
        ile[mask][i] = dp[SZ(ogr)][i];
}

LL sol2(LL x) {
    REP(m,MASKS) {
        count(m,x);
//        REP(r,MOD)
//            if(ile[m][r])
//                cout << "ile " << m << " " << r << " = " << ile[m][r] << endl;
    }
    LL res = 0;
    REP(m,MASKS) FORE(r,reszty[m]) {
        dobre[m][*r] = ile[m][*r];
        FORE(s,sub[m])
                dobre[m][*r] -= dobre[*s][*r];
//        if(dobre[m][*r]>0)
//                cout << "dobre " << m << " " << *r << " = " << dobre[m][*r] << "   " << ile[m][*r] << endl;
        res += dobre[m][*r];
    }
//    cout << "sol " << x << " " << res << endl;
    return res;
}

LL sol(LL l, LL r) {
    return sol2(r+1)-sol2(l);
}


LL t,l,r;

int main(){
    REP(i,MOD) REP(j,10)
        move[i][j] = (i*10+j)%MOD;
    REP(i,MASKS) {
        REP(j,i)
        if((j&(~i)) == 0)
            sub[i].PB(j);
        REP(r,MOD) {
            bool ok = true;
            REP(p,10)
                if(i&(1<<p))
                    if(r%(2+p) != 0)
                        ok = false;
            if(ok)
                reszty[i].PB(r);
        }
    }
    ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--){
        cin >> l >> r;
        cout << sol(l,r) << endl;
    }
    return 0;
}