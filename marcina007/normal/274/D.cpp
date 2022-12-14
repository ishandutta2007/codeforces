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
#define MAXN 1000007

int n,m,act,vis[MAXN],v[MAXN];
VI G[MAXN];
VI post;
bool zle = false;

void go(int x){
    vis[x] = 1;
    FORE(i,G[x]) {
        if(vis[*i] == 1) {zle=true; return;}
        if(!vis[*i])
            go(*i);
    }
    vis[x] = 2;
    if(x<=m) post.PB(x);
}

int main(){
	ios_base::sync_with_stdio(false);
	//in
    cin >> n >> m;
	//sol
    act = m+1;
    REP(i,n) {
        FOR(j,1,m) cin >> v[j];
        vector<P> w;
        FOR(j,1,m) if(v[j] != -1) w.PB(P(v[j],j));
        sort(ALL(w));
        REP(j,SZ(w)) {
            if(j>0 && w[j-1].X != w[j].X) act++;
            G[act].PB(w[j].Y);
            G[w[j].Y].PB(act+1);
        }
        act+=2;
    }
	//out
    FOR(i,1,m) if(!vis[i]) go(i);
    if(zle) cout << -1 << endl;
    else {
        reverse(ALL(post));
        FORE(i,post) cout << *i << " ";
        cout << endl;
    }
	return 0;
}