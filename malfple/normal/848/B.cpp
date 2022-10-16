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
typedef unsigned long long ull;
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

#define getc getchar
template<typename T>
T getnum(){
	int sign = 1;
	T ret = 0;
	char c;

	do{
		c = getc();
	}while(c == ' ' || c == '\n');
	if(c == '-')sign = -1;
	else ret = c-'0';
	while(1){
		c = getc();
		if(c < '0' || c > '9')break;
		ret = 10*ret + c-'0';
	}
	return sign * ret;
}

inline void ini(int& x){
	x = getnum<int>();
}

inline void scani(int& x){
	scanf("%d",&x);
}

//end of macro

const int N = 1e5 + 5;

int n,w,h;
int g[N];
int x[N];
int y[N];
int nx[N];
int ny[N];
vector<pii>vec[2*N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>w>>h;
    REP(i,1,n){
        int p,t;
        cin>>g[i]>>p>>t;
        if(g[i] == 1){
            x[i] = p;
            y[i] = h;
        }else{
            x[i] = w;
            y[i] = p;
        }

        int diag = N + p - t;
        //cout << diag<<endl;
        if(g[i] == 1)p += t;
        else p = -p-t;
        //printf("%d %d\n",i,p);
        vec[diag].pb(mp(p, i));
    }

    REP(i,0,2*N-1){
        if(vec[i].empty())continue;
        //cout << i << endl;
        vi a,b;

        sort(vec[i].begin(), vec[i].end());
        int last = -1;
        FOR(j,vec[i].size()){
            if(g[vec[i][j].ss] == 1)a.pb(vec[i][j].ss);
            else b.pb(vec[i][j].ss);
        }
        FOR(j,vec[i].size()){
            if(g[vec[i][j].ss] == 2)a.pb(vec[i][j].ss);
            else b.pb(vec[i][j].ss);
        }
        FOR(j,a.size()){
            //printf("%d -> %d\n",b[j],a[j]);
            nx[b[j]] = x[a[j]];
            ny[b[j]] = y[a[j]];
        }
    }

    REP(i,1,n)cout << nx[i] << " " << ny[i] << endl;

    return 0;
}

/*
6 10 10
1 1 1
1 2 2
1 3 3
2 1 1
2 2 2
2 3 3
*/