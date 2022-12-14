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
#define MAXN 1000007

LL n,l,t;
vector<LL> a;
LL res;

LL sol(LL x,LL y,LL skip) {
    if(y < x) return 0;
    if(y >= l) {
        return sol(x,l-1,skip) + sol(0,y%l,skip) + ((y/l)-1) * (n-1);
    }
    int xx = lower_bound(ALL(a),x) - a.begin();
    int yy = upper_bound(ALL(a),y) - a.begin();
//    cout << x << "-" << y << " = " << xx << " " << yy << endl;
    return yy-xx-(x <= skip && skip <= y);
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(9) << fixed;
	//in
    cin >> n >> l >> t;
    FOR(i,1,n) {
        int x;
        cin >> x;
        a.PB(x);
    }
	//sol
        FORE(i,a) res += sol(*i, *i + 2*t, *i);
	//out
    cout << ((LD)res) / 4 << endl;
	return 0;
}