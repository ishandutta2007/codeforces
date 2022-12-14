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
typedef complex<int> P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 300007

LL wek(P a,P b){return (LL)a.real()*b.imag()-(LL)a.imag()*b.real();}
LL skret(P a,P b,P c){return wek(b-a,c-a);}

LL n,m,skok[MAXN],sum[MAXN];
P p[MAXN], srod[MAXN];

P in(){
    int x,y;
    cin >> x >> y;
    return P(x,y);
}

LL getsum(int a,int b){
    if(b<a) return 0;
    return sum[b] - (a ? sum[a-1] : 0);
}

int main(){
    ios_base::sync_with_stdio(false);
    //in
    cin >> n;
    REP(i,n) p[i] = in();
    cin >> m;
    REP(i,m) srod[i] = in();
    REP(i,n)
        p[2*n+i]=p[n+i]=p[i];
    //sol
    REP(s,m) {
        bool ok = true;
        REP(i,n) if(skret(p[i],p[i+1], srod[s]) > 0) ok=false;
//        REP(i,n) cout << p[i] << " " << p[i+1] << " " << srod[s] << " " << skret(p[i],p[i+1], srod[s]) << endl;;

        if(!ok){
            cout << 0 << endl;
            continue;
        }
        REP(i,n) {
            skok[i] = min(i+1, (int)n-1);
            if(i) maxi(skok[i], skok[i-1]);
            while(skok[i]+1 < n && skret(p[i], p[skok[i]+1], srod[s]) <= 0)
                skok[i]++;
        }
        sum[0] = skok[0];
        FOR(i,1,n-1)
            sum[i] = sum[i-1] + skok[i];
        LL res = 0;
        REP(i,n-2)
            res += getsum(i+1, skok[i]) - ((LL)skok[i] * (skok[i]-i));
        //out
        cout << res << endl;
    }
    return 0;
}