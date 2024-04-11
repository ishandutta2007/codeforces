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
#define MAXN 100007

int n,x1,y11,x2,y2;

int main(){
    ios_base::sync_with_stdio(false);
    //in
    cin >> n >> x1 >> y11 >> x2 >> y2;
    int res = 2*n;
    REP(i,2){
        if(x1 == x2 && (x1 == 0 || x1 == n)) mini(res, abs(y11-y2));
        if(y11%n == 0 && y2%n == 0) mini(res, x1 + x2 + abs(y11-y2));
        if(y11%n == 0 && y2%n == 0) mini(res, 2*n - x1 - x2 + abs(y11-y2));
        REP(a,2) REP(b,2) {
            int d1 = INF, d2 = INF;
            if(n*a == x1) mini(d1, abs(n*b - y11));
            if(n*b == y11) mini(d1, abs(n*a - x1));
            if(n*a == x2) mini(d2, abs(n*b - y2));
            if(n*b == y2) mini(d2, abs(n*a - x2));
            mini(res, d1+d2);
        }
        swap(x1,y11);
        swap(x2,y2);
    }
    //sol
    cout << res << endl;
    //out
    return 0;
}