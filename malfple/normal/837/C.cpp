#include <iostream>
#include <iomanip>
#include <cstdio>

#include <cstring>
#include <string>
#include <sstream>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=(int)a-1; i>=0; i--)

#define mp make_pair

#define pb push_back
#define ff first
#define ss second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

//end of macro

const int N = 105;

int n,a,b;
int x[N], y[N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin>>n>>a>>b;
    REP(i,1,n)cin>>x[i]>>y[i];

    int ans = 0;
    REP(i,1,n){
        REP(j,1,n){
            if(i==j)continue;
            bool can = false;
            REP(k,0,3){
                int xa = x[i];
                int ya = y[i];
                int xb = x[j];
                int yb = y[j];

                if(k&1)swap(xa,ya);
                if(k&2)swap(xb,yb);

                if((xa+xb <= a && max(ya,yb) <= b) || (max(xa,xb) <= a && ya+yb <= b)){
                    can = true;
                }
            }
            if(can)ans = max(ans, x[i]*y[i] + x[j]*y[j]);
        }
    }
    cout << ans << endl;

    return 0;
}