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
typedef unsigned int uint;


uint in() {
    char c;
    uint res=0;
    REP(i,4) {
        if(i) {
            cin >> c;
            assert(c == '.');
        }
        uint d;
        cin >> d;
        res |= (d << (8*(3-i)));
    }
    return res;
}

void out(uint x) {
    REP(i,4) {
        if(i) cout << ".";
        cout << ((x >> (8*(3-i)))&255);
    }
    cout << endl;
}

int n,k;
uint ip[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> k;
    REP(i,n) ip[i] = in();
	//sol
    FORD(p,31,1) {
        uint mask = 0;
        FOR(i,p,31)
            mask |= (1u << i);
        vector<uint> v;
        REP(i,n)
            v.PB(ip[i]&mask);
        sort(ALL(v));
        v.erase(unique(ALL(v)),v.end());
        if(SZ(v) == k) {
            out(mask);
            return 0;
        }
    }
	//out
    cout << -1 << endl;
	return 0;
}