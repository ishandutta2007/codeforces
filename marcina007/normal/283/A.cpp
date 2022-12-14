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
#define MAXN 200007

LL x[MAXN],add[MAXN],n,m,sum;

int main(){
	ios_base::sync_with_stdio(false);
	//in
    cin >> n;
    m = 1;
    while(n--) {
        int type;
        cin >> type;
        if(type == 1) {
            LL a,v;
            cin >> a >> v;
            add[a] += v;
            sum += a*v;
        } else if(type == 2) {
            LL k;
            cin >> k;
            x[++m] = k;
            sum += k;
        } else if(type == 3) {
            x[m] += add[m];
            add[m-1] += add[m];
            add[m] = 0;
            sum -= x[m];
            m--;
        }
        cout << fixed << setprecision(9) << ((LD)sum)/m << endl;
    }
	//sol
	//out
	return 0;
}