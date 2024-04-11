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
#define FOR(i, a, b) for(LL i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(LL i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(LL i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((LL)(x).size())
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
typedef vector<LL>VI;
const LL INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 1000007

LL n,m,k,len[2],ile[2],val;
P best;
map<P, vector<P> > M;
map<LL, P> kto;

int main(){
    ios_base::sync_with_stdio(false);
    //in
    cin >> n >> m >> k;
    len[0] = m;
    len[1] = n;
    while(k--) {
        LL x,y,xx,yy;
        cin >> x >> y >> xx >> yy;
        if(x == xx) {
            M[P(x,0)].PB(P(min(y,yy),1));
            M[P(x,0)].PB(P(max(y,yy),-1));
        } else {
            M[P(y,1)].PB(P(min(x,xx),1));
            M[P(y,1)].PB(P(max(x,xx),-1));
        }
    }
    //sol
    FORE(i,M) {
        ile[i->X.Y]++;
        vector<P> v = i->Y;
        sort(ALL(v));
        LL cnt = 0, act = 0, last = 0;
        FORE(j,v) {
            if(j->X != last) {
                if(act==0) cnt += j->X-last;
                last = j->X;
            }
            act += j->Y;
        }
        cnt += len[i->X.Y] - last;
        kto[cnt] = i->X;
//        cout << i->X.X << "/" << i->X.Y << " " << cnt << endl;
        val ^= cnt;
    }
    REP(i,2) if((len[1-i]-1-ile[i])%2) {
            P p = P(1,i);
            while(M.count(p))
                p.X++;
            kto[len[i]] = p;
        val ^= len[i];
    }
    //out
    if(val == 0)
        cout << "SECOND" << endl;
    else {
        cout << "FIRST" << endl;
        LL usun, naj;
        FORE(i,kto) {
            naj = i->X;
            usun = naj - (val^naj);
            if(1 <= usun && usun <= naj) {
                best = i->Y;
                break;
            }
        }
        vector<P> v = M[best];
        sort(ALL(v));
        assert(usun>0);
  //      cout << val << " " << naj << " " << usun <<  "     " << best.X << "/" << best.Y << endl;
        LL cnt = 0, act = 0, last = 0;
        FORE(j,v) {
            if(j->X != last) {
                if(act==0){
                    LL jest = j->X-last;
                    if(jest >= usun) goto kon;
                    usun -= jest;
                }
                last = j->X;
            }
            act += j->Y;
        }
kon:
                    LL zak = last + usun;
        //            assert(zak <= len[best.Y]);
                    if(best.Y == 0)
                        cout << best.X << " " << 0 << " " << best.X << " " << zak << endl;
                    else
                        cout << 0 << " " << best.X << " " << zak << " " << best.X << endl;
                    return 0;
    }
    return 0;
}