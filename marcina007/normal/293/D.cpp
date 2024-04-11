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
#include<stack>
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
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 100007

#define TYP LL
typedef complex<TYP> P;
inline TYP operator^(P a, P b) { return real(a) * imag(b) - imag(a) * real(b); }//iloczyn wektorowy
inline TYP operator%(P a, P b) { return real(a) * real(b) + imag(a) * imag(b); }//iloczyn skalarny
// w prawo <=> skret < 0
inline TYP skret(P a, P b, P c) { return (b - a) ^ (c - a);}

#define ZAK ((int)2E6+7)
int n;
vector<P> p;
int cnt[ZAK];
LD res;
bool vis[ZAK][2];

void add(P a,P b){
//    cout << "Add " << a << " " << b << endl;
    if(a.X == b.X) return;
        bool t = (b.X > a.X);
        FOR(x, min(a.X,b.X), max(a.X,b.X)) {
            LL low = (a.Y * (b.X - a.X) + (b.Y - a.Y) * (x - a.X)) / (b.X - a.X);
            if(!t && skret(a, b, P(x, low)) == 0) low--;
//            cout << x-ZAK/2 << " tryb " << (b.X > a.X) << " val " << low << endl;
            if(vis[x][t]) continue;
            cnt[x] += low * (t ? 1 : -1);
            vis[x][t] = true;
        }
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n;
    REP(i,n) {
        int x,y;
        cin >> x >> y;
        p.PB(P(x+ZAK/2,y+ZAK/2));
    }
    REP(i,SZ(p)-2)
        if(skret(p[i], p[i+1], p[i+2]) > 0) {
            reverse(ALL(p));
            break;
        }
	//sol
    REP(_,2) {
        CLR(cnt); CLR(vis);
        p.PB(p[0]);
        REP(i,SZ(p)-1) add(p[i], p[i+1]);
//        REP(i,ZAK) if(cnt[i] && cnt[i] != 2000001) cout << i-ZAK/2 << " -> " << cnt[i] << endl;
        p.pop_back();
        LD sum = 0, all = 0;
        REP(i,ZAK) sum += (LL)i * cnt[i], all += cnt[i];
        LD srod = sum / all;
        LD act = 0, baza = 0;
        REP(i,ZAK) baza += SQR(i - srod) * cnt[i];
        REP(i,ZAK) act += (baza + SQR(i - srod) * all) * cnt[i];
        res += act / (all * (all - 1));
        //
        FORE(i,p) swap(i->X, i->Y);
        reverse(ALL(p));
    }
	//out
    cout << res/2 << endl;
	return 0;
}