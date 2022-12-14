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

int n,k,p[9];
LL res;
int vis[9];

void go(int m) {
    if(m == k+1) {
        CLR(vis);
        vis[1] = 1;
        FOR(i,2,k) if(!vis[i]){
            int j;
            for(j=i; !vis[j]; j=p[j])
                vis[j] = i;
        if(vis[j] == i) return;
        }
        res++;
    } else {
        FOR(i,1,k) {
           p[m] = i;
           go(m+1); 
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n >> k;
	//sol
    if(k == 1)
        res = 1;
    else
        go(2);
	//out
    res %= INF;
    res *= k;
    res %= INF;
    REP(i,n-k) res = (res * (n-k)) % INF;
    cout << res << endl;
	return 0;
}