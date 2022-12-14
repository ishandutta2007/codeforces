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
#define MAXN 80007

LL n;
VI G[MAXN];
LL W[MAXN],T[MAXN],SP[MAXN],R[MAXN],RR;

void go(int i,int o) {
    //W
    W[i] = 1;
    FORE(s,G[i]) if(*s != o) {
        go(*s, i);
        W[i] += W[*s];
    }
    //T
    T[i] = W[i]-1;
    LL popT = 0;
    FORE(s,G[i]) if(*s != o) {
        T[i] += W[*s] * popT;
        popT += W[*s];
    }
    //SP
    SP[i] = W[i] * T[i];
    FORE(s,G[i]) if(*s != o) {
        SP[i] += SP[*s];
    }
    //R
    LL popR = n - W[i] + 1;
    R[i] = T[i] * (n - W[i]);
    FORE(s,G[i]) if(*s != o) {
        R[i] += SP[*s] * (W[i] - W[*s]);
        R[i] += T[i] * W[*s] * popR;
        popR += W[*s];
    }
    RR += R[i];
//    cout << i << " W " << W[i] << " T " << T[i] << " SP " << SP[i] << " R " << R[i] << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n;
    REP(i,n-1) {
        int a,b;
        cin >> a >> b;
        G[a].PB(b);
        G[b].PB(a);
    }
	//sol
    go(1,1);
	//out
    cout << SQR(n*(n-1)/2) - RR << endl;
	return 0;
}