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

const int N = 100005;
const int M = 105;

int n,q,cmax;
int x[N], y[N], c[N];
int prefsum[M][M][15];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

	cin>>n>>q>>cmax;
	cmax++;
	REP(i,1,n)cin>>x[i]>>y[i]>>c[i];
	
	REP(i,0,cmax-1){
		REP(j,1,n){
			prefsum[x[j]][y[j]][i] += c[j];
			
			c[j] = (c[j]+1)%cmax;
		}
		
		REP(j,0,M-5)REP(k,1,M-5)prefsum[j][k][i] += prefsum[j][k-1][i];
		REP(j,0,M-5)REP(k,1,M-5)prefsum[k][j][i] += prefsum[k-1][j][i];
	}
	
	REP(i,1,q){
		int t,a,b,c,d;
		cin>>t>>a>>b>>c>>d;
		t = t%cmax;
		
		int sum = prefsum[c][d][t];
		sum -= prefsum[a-1][d][t];
		sum -= prefsum[c][b-1][t];
		sum += prefsum[a-1][b-1][t];
		
		cout << sum << endl;
	}

    return 0;
}