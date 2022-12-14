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
const LL INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 100007

LL pot(LL x,int n){
    if(!n) return 1;
    if(n%2) return (pot(x,n-1)*x)%INF;
    return pot((x*x)%INF, n/2);
}

LL odw(LL x){return pot(x,INF-2);}
LL sil(int n){
    LL res = 1;
    FOR(i,1,n) res=(res*i)%INF;
    return res;
}

LL dw(LL n,LL k){
    return ((sil(n)*odw(sil(k)))%INF*odw(sil(n-k)))%INF;
}

int main(){
    ios_base::sync_with_stdio(false);
    //in
    int n;
    cin >> n;
    LL res = 2*dw(2*n-1,n)-n;
    res %= INF;
    if(res<0) res += INF;
    //sol
    cout << res << endl;
    //out
    return 0;
}