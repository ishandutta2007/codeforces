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
typedef vector<LL>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 1000007

vector<VI> v[4];
string op[3];

int main(){
    ios_base::sync_with_stdio(false);
    //in
    VI in;
    REP(i,4){
        LL x;
        cin >> x;
        in.PB(x);
    }
    v[0].PB(in);
    REP(i,3) cin >> op[i];
    //sol
    REP(i,3) {
        FORE(j,v[i]) {
            vector<LL> w = *j;
            REP(a,SZ(w))
                REP(b,a) {
                    vector<LL> next;
                    REP(k,SZ(w))
                        if(k != a && k != b)
                            next.PB(w[k]);
                    next.PB(op[i][0] == '*' ? w[a]*w[b] : w[a]+w[b]);
                    v[i+1].PB(next);
                }
        }
    }
    sort(ALL(v[3]));
//    cout << v[3].size() << endl;
    cout << v[3][0][0] << endl;
    //out
    return 0;
}