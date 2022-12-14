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

#define MAXN 5007
LL n,a[MAXN],v[MAXN];
int dp[MAXN], pot[MAXN], res;

inline bool ok(int i,int j){
    if(v[i]%v[j] != 0) return false;
    return (pot[j] == pot[i]+j-i || pot[j] <= j-i-1);
}

int main(){
	ios_base::sync_with_stdio(false);
	//in
    cin >> n;
    FOR(i,1,n) cin >> a[i];
	//sol
    FOR(i,1,n) {
        v[i] = a[i];
        while(v[i]%2 == 0) {
            v[i] /= 2;
            pot[i]++;
        }
    }
    FOR(j,1,n) {
        dp[j] = 1;
        FOR(i,1,j-1)
            if(ok(i,j))
                maxi(dp[j], dp[i]+1);
        maxi(res, dp[j]);
    }
    //out
    cout << n-res << endl;
	return 0;
}