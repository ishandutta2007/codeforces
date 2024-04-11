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
#define DEBUG 0
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
#define MAXN (1<<17)

struct Tree{
    bool rev[2*MAXN+7];
    int count[2*MAXN+7][2];

    void set(int x,int s) {
        if(x>=2*MAXN) return;
        count[x][0] = s;
        set(2*x,s/2);
        set(2*x+1,s/2);
    }

    Tree(){
        set(1,MAXN);
    }

    void update(int x) {
        if(2*x+1 < 2*MAXN) {
            REP(i,2)
                count[x][i] = count[2*x][i] + count[2*x+1][i];
        } else {
            count[x][0] = 1;
            count[x][1] = 0;

        }
        if(rev[x])
            swap(count[x][0], count[x][1]);
        debug("update " << x << " " << rev[x] << " " << count[x][0] << "/" << count[x][1]);
    }

    void swapm(int l,int r,int x=1,int ll=1,int rr=MAXN) {
        if(x==1) debug("swap " << l << " " << r);
        if(r < ll || rr < l) return;
        if(l <= ll && rr <= r)
            rev[x] ^= 1;
        else {
            swapm(l,r,2*x,ll,(ll+rr)/2);
            swapm(l,r,2*x+1,(ll+rr+1)/2,rr);
        }
        update(x);
    }

    int get(int l,int r,bool v,int x=1,int ll=1,int rr=MAXN) {
        if(x==1) debug("get " << l << " " << r << " " << v);
        if(r < l || r < ll || rr < l) return 0;
        if(l <= ll && rr <= r) return count[x][v];
        return get(l,r,v^rev[x],2*x,ll,(ll+rr)/2) + get(l,r,v^rev[x],2*x+1,(ll+rr+1)/2,rr);
    }
};

Tree tree;

int n,k,s[MAXN],a[MAXN],b[MAXN];
vector<P> e[MAXN];

LL dw2(LL x){return x*(x-1)/2;}
LL dw3(LL x){return x*(x-1)*(x-2)/6;}

int main(){
	ios_base::sync_with_stdio(false);
	//in
    cin >> n >> k;
    FOR(i,1,n) cin >> s[i];
    FOR(i,1,k) cin >> a[i] >> b[i];
    //tran
    VI v;
    v.PB(-1);
    FOR(i,1,n) v.PB(s[i]);
    sort(ALL(v));
    v.erase(unique(ALL(v)),v.end());
    FOR(i,1,n) s[i] = lower_bound(ALL(v), s[i]) - v.begin();
    FOR(i,1,k) {
        a[i] = lower_bound(ALL(v), a[i]) - v.begin();
        b[i] = upper_bound(ALL(v), b[i]) - v.begin() - 1;
    }
    //FOR(i,1,n) cout << s[i] << " "; cout << endl;
    //FOR(i,1,k) cout << a[i] << "-" << b[i] << " "; cout << endl;
	//sol
    FOR(i,1,k) if(a[i] <= b[i]) {
        e[a[i]].PB(P(a[i],b[i]));
        e[b[i]+1].PB(P(a[i],b[i]));
    }
    LL res = dw3(n);
    debug(res);
    FOR(i,1,n) {
        debug(i);
        FORE(j,e[i]) {
            debug("OK");
            tree.swapm(j->X,j->Y);
        }
        int act = tree.get(1,i-1,0) + tree.get(i+1,n,1);
        debug(act);
        res -= dw2(act);
    }
	//out
    cout << res << endl;
	return 0;
}