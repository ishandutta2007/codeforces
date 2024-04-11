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
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 100007

LD w,h,alfa,t,c;
bool ok;

LD go(LD w) {
    LD b = (w-t*h/(1.0+c)) / ((1.0+c)-t*t/(1.0+c));
    LD s = (w+h)/(1.0+c+t) - b;
    LD res = w*h-(b*b+s*s)*t;
    ok = (b >= -1E-9) && (s >= 1E-9) && (res >= 1E-9);
    return res;
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> w >> h >> alfa;
    if(alfa > 90)
        alfa = 180 - alfa;
	//sol
    if(w < h) swap(w,h);
    t = tanl(alfa*M_PI/180.0l);
    c = 1.0/cosl(alfa*M_PI/180.0l);
    LD low = h, high = w;
    REP(_,100) {
        LD mid=(low+high)/2;
        go(mid);
        if(ok)
            low = mid;
        else
            high = mid;
    }
//    cout << t << "  " << s << " " << b << endl;
//    cout << b*t+(1+c)*s << " " << h << endl;
//    cout << (1+c)*b+s*t << " " << w << endl;
	//out
    cout << go(low) << endl;
	return 0;
}