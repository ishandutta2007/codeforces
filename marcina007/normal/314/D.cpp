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
typedef pair<LL, LL>P;
typedef vector<int>VI;
const LL INF=1E11+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 100007

int n;
P p[MAXN];
LL maxy[MAXN], miny[MAXN];

bool test(LL d) {
    LL maxY = -INF, minY = INF;
    int j = 0;
    FOR(i,0,n-1) {
        while(j<n && p[j].X < p[i].X - d) {
            maxi(maxY, p[j].Y);
            mini(minY, p[j].Y);
            j++;
        }
        if(max(maxY, maxy[i+1]) - min(minY, miny[i+1]) <= d)
            return true;
    }
    return false;
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n;
    REP(i,n) {
        LL x,y;
        cin >> x >> y;
        p[i] = P((x+y), (x-y));
    }
	//sol
    sort(p,p+n);
    maxy[n] = -INF;
    miny[n] = INF;
    FORD(i,n-1,0) maxy[i] = max(maxy[i+1], p[i].Y);
    FORD(i,n-1,0) miny[i] = min(miny[i+1], p[i].Y);
    LL low = 0, high = INF;
    while(low < high) {
        LL mid = (low + high) / 2;
        if(test(mid))
            high = mid;
        else
            low = mid + 1;
    }
	//out
    cout << ((LD)low) / 2.0 << endl;
	return 0;
}