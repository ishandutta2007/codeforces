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
#define MAXN 1007

LL count2, sum, n, m, row[MAXN], col[MAXN];
vector<P> p;
char pl[MAXN][MAXN];
LL go(LL x){return (x*(x+1))/2;}

int main(){
    ios_base::sync_with_stdio(false);
    //in
    cin >> n >> m;
    FOR(i,1,n) cin >> &pl[i][1];
    //sol
    REP(faza,2){
        CLR(row); CLR(col);
    FOR(i,1,n) FOR(j,1,m) if(pl[i][j] == 'X') {
        row[i] = j;
        col[j] = i;
    }
    FOR(i,1,n) FOR(j,1,m) if(pl[i][j] == 'X') {
        if(faza) p.PB(P(i,j));
//        sum += 4*(i-1)*(n-i) + 4*(j-1)*(m-j);
        LL ile = j-1;
        FORD(q,i-1,1){
            if(!row[q] || row[q]>row[q+1]) break;
            ile += row[q]-1;
        }
        sum += 4*ile*(m-j);
        ile = 0;
        FOR(q,i+1,n){
            if(!row[q] || row[q]>row[q-1]) break;
            ile += row[q]-1;
        }
        sum += 4*ile*(m-j);
    }
    FOR(i,1,1000) FOR(j,1,i-1)
        swap(pl[i][j], pl[j][i]);
    swap(n,m);
    }
 //   cout << sum << endl;
    LL all = n*m - SZ(p);
    FOR(i,1,n) FOR(j,1,m) {
        sum += (go(i-1)+go(n-i)) * m * (pl[i][j] == 'X' ? -1 : 1);
//        cerr << "!" << sum << endl;
        sum += (go(j-1)+go(m-j)) * n * (pl[i][j] == 'X' ? -1 : 1);
//        cerr << "!" << sum << endl;
    }
//    cout << sum << endl;
    FORE(i,p) FORE(j,p) if(i != j)
        sum += (abs(j->X - i->X) + abs(j->Y - i->Y));

    count2 = all*all;
    //out
//    cout << sum << " " << count2 << endl;
    cout << fixed << setprecision(9) << ((long double)sum/count2) << endl;
    return 0;
}