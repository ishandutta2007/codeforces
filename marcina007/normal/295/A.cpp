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

int n,m,k;
int l[MAXN],r[MAXN],d[MAXN],x[MAXN],y[MAXN],a[MAXN];
LL ile[MAXN], add[MAXN];

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> m >> k;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,m) cin >> l[i] >> r[i] >> d[i];
    FOR(i,1,k) cin >> x[i] >> y[i];
	//sol
    FOR(i,1,k)
        ile[x[i]]++, ile[y[i]+1]--;
    FOR(i,1,m) {
        ile[i] += ile[i-1];
        add[l[i]] += ile[i] * d[i];
        add[r[i]+1] -= ile[i] * d[i];
    }
	//out
    FOR(i,1,n) {
        add[i] += add[i-1];
        cout << a[i] + add[i] << " " ;
    }
    cout << endl;
	return 0;
}