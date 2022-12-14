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

int n,m;
LL res,rem;

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(9) << fixed;
	//in
    cin >> n >> m;
	//sol
    FOR(i,1+m,n-m) {
        if(i == n - n/2 + 1) {
            res += rem;
            break;
        }
        int a = 2*i*i-i*m-2*i*(n+1)+m*(n+1);
        a = -a+i+m-1;
        int v = n-i;
        int prog1 = m+1, prog2 = n-m+1;
        int zp = 1+m, zk = n-m;
        FOR(j,zp,zk) {
        a -= v;
        int b = a / (i+j);
        if(b < prog1) {res += (LL)prog1 * (n-m-j+1); break;}
        if(b > prog2) res += prog2;
        else res += b;
        }
        res -= (LL)(n-2*m) * prog1;
        if(i == n/2) rem = res;
    }
	//out
    cout << 3*res << endl;
	return 0;
}