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
#include<stack>
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
#define ABS(a) ((a)>0?(a):(-a))
#define DEBUG 1
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<int, int> P;
typedef vector<int> VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 100007

vector<P> v;
int n,a[MAXN],b[MAXN],c,p1,p2,p3;

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n;
    FOR(i,1,n) {
        int x;
        cin >> x;
        v.PB(P(x,i));
    }
	//sol
    p1 = p2 = n/3;
    if(n%3 > 0) p1++;
    if(n%3 > 1) p2++;
    p3 = n - p1 - p2;
    v.PB(P(-1,-1));
    sort(ALL(v));
    FOR(i,1,p1) {
        a[v[i].Y] = 0;
        b[v[i].Y] = v[i].X;
    }
    FOR(i,p1+1,p1+p2) {
        a[v[i].Y] = v[i].X;
        b[v[i].Y] = 0;
    }
    c = p3+1;
    FOR(i,p1+p2+1,n) {
        a[v[i].Y] = --c;
        b[v[i].Y] = v[i].X - c;
    }
	//out
    cout << "YES" << endl;
    FOR(i,1,n) cout << a[i] << " "; cout << endl;
    FOR(i,1,n) cout << b[i] << " "; cout << endl;
	return 0;
}