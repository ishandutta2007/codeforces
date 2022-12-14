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

LL val[MAXN],a[MAXN],vis[MAXN],n;

void go(int v) {
    val[v] = 0;
    int x = v;
    val[v] += a[x];
    vis[v] = 1;
    x += a[x];
    if(x < 1 || x > n) {
        vis[v] = 2;
        return;
    }
    val[v] += a[x];
    x -= a[x];
    if(x < 1 || x > n) {
        vis[v] = 2;
        return;
    }
    if(vis[x] == 1) {
        val[v] = -1;
    } else {
        if(vis[x] == 0)
            go(x);
        if(val[x] == -1) val[v] = -1;
        else val[v] += val[x];
    }
    vis[v] = 2;
}

int main(){
	ios_base::sync_with_stdio(false);
	//in
    cin >> n;
    FOR(i,2,n) cin >> a[i];
	//sol
    vis[1] = 2;
    val[1] = -1;
    FOR(i,1,n) if(vis[i] != 2) go(i);
	//out
    FOR(i,1,n-1) {
        a[1] = i;
        val[1] = vis[1] = 0;
        go(1);
        cout << val[1] << endl;
    }
	return 0;
}