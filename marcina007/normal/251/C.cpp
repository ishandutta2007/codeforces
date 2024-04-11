#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <stack>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <complex>
#include <queue>
#include <algorithm>
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin(); i != (x).end(); ++i)
#define ALL(x) x.begin(),(x).end()
#define SZ(x) ((x).size())
#define X first
#define Y second
#define CLR(x) memset((x),0,sizeof(x))
typedef long long int LL;
typedef long long unsigned int LLU;
typedef long double LD;
typedef pair<int, int> P;
typedef vector<int> VI;

#define LIM 360360
#define INF ((LL)(1E18+1))
#define SIZE 16

struct M{
    LL t[SIZE][SIZE];
    M(){REP(i,SIZE) REP(j,SIZE) t[i][j]=INF;}
};

M operator*(M a,M b){
    M res;
    REP(i,SIZE) REP(j,SIZE) REP(k,SIZE)
        res.t[i][j] = min(res.t[i][j], a.t[i][k] + b.t[k][j]);
    return res;
}

M pot(M a, LL n){
    if(n == 1)
        return a;
    if(n%2)
        return pot(a,n-1)*a;
    return pot(a*a,n/2);
}

LL a,b,k;
M m;

int dp[5*LIM];

VI kraw[LIM];


inline void move(int x, int y){
//    map<LL, LL>::iterator it = M.find(x);
//    if(it == M.end() || it->Y > y)
//        M[x] = y;
    if(x>=0) dp[x] = min(dp[x], y);
}


void go(int high, int low) {
    for(int i = high; i >= low; i--) {
        FORE(j,kraw[i%LIM])
            move(i-*j, dp[i]+1);
    }
}

int sol(int a,int b){
    REP(i,a+1) dp[i]=1E9;
    dp[a] = 0;
    go(a,b);
    return dp[b];
}

LL pocz[SIZE], kon[SIZE];

int main(){
    ios_base::sync_with_stdio ( false );
    //in
    cin >> a >> b >> k;
    LL d = (b/LIM)*LIM;
    a -= d; b -= d;
    //
    REP(i,LIM) {
        kraw[i].PB(1);
        FOR(j,2,k)
            kraw[i].PB(i%j);
        sort(ALL(kraw[i]));
        kraw[i].erase(unique(ALL(kraw[i])), kraw[i].end());
    }
    //
    LL res = INF;
    if(a < 4*LIM) {
        res = sol(a,b);
    } else {
        REP(i,SIZE) {
            REP(j,2*LIM) dp[j] = 1E9;
            dp[LIM+i] = 0;
            go(LIM+i, 0);
            REP(j,SIZE)
                m.t[i][j] = dp[j];
        }
        LL base = ((a-20)/LIM)*LIM;
        LL base2 = LIM;
        LL dist = (base - base2) / LIM;
        m = pot(m, dist);
//        REP(i,SIZE) {
//            REP(j,SIZE) cout << m.t[i][j] << " "; cout << endl;
//        }
        REP(i,SIZE) pocz[i] = sol(a-base, i);
        REP(i,SIZE) kon[i] = sol(base2+i, b);
//        REP(i,SIZE) cout << pocz[i] << " " << kon[i] << endl;
        REP(i,SIZE) REP(j,SIZE)
            res = min(res, pocz[i] + m.t[i][j] + kon[j]);
    }
    cout << res << endl;
    //sol
    //out
    return 0;
}