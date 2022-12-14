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
const int INF=2E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN (1<<18)

struct Tree{
    int dp[2*MAXN+7], best[MAXN+7];

    Tree(){
        REP(i,2*MAXN+7) dp[i] = INF;
    }

    void ust(int l,int r,int v,int x=1,int ll=1,int rr=MAXN) {
 //       if(x==1) cout << "ust " << l << "-" << r << " " << v << endl;
        if(r < l || r < ll || rr < l) return;
        if(l <= ll && rr <= r) mini(dp[x], v);
        else {
            ust(l,r,v,2*x,ll,(ll+rr)/2);
            ust(l,r,v,2*x+1,(ll+rr+1)/2,rr);
        }
    }

    void prop(int l = 1,int r=MAXN,int v=INF,int x=1) {
        mini(v, dp[x]);
        if(l == r) best[l] = v;
        else { 
            prop(l,(l+r)/2,v,2*x);
            prop((l+r+1)/2,r,v,2*x+1);
        }
    }
};

Tree tree;

int n,m,l[MAXN],r[MAXN],t[MAXN],q[MAXN],ans[MAXN];
VI wsp;
LL sum = 0, kor = 0;

struct E{
    int co;
    int kto;
    int kiedy;
    E(int co_, int kto_, int kiedy_){co=co_; kto=kto_; kiedy=kiedy_;}
    bool operator<(const E& e) const {
        return kiedy < e.kiedy;
    }
};

vector<E> events;

int main(){
	ios_base::sync_with_stdio(false);
	//in
    cin >> m >> n;
    FOR(i,1,n) cin >> l[i] >> r[i] >> t[i];
    FOR(i,1,m) cin >> q[i];
    //tran
    wsp.PB(-1);
    FOR(i,1,n) wsp.PB(l[i]),wsp.PB(r[i]);
    sort(ALL(wsp));
    wsp.erase(unique(ALL(wsp)), wsp.end());
    FOR(i,1,n) {
        l[i] = lower_bound(ALL(wsp), l[i]) - wsp.begin();
        r[i] = lower_bound(ALL(wsp), r[i]) - wsp.begin();
    }
//    FOR(i,1,n) cout << l[i] << "-" << r[i] << " " << t[i] << endl;
//    FORE(i,wsp) cout << *i << " "; cout << " w" << endl;
    //best
    FOR(i,1,n) {
        tree.ust(l[i], r[i]-1, t[i]);
    }
    tree.prop();
    //sol
    FOR(i,1,MAXN) if(tree.best[i] < INF) {
 //       cout << "best " << i << " " << tree.best[i] << endl;
        events.PB(E(1, i, tree.best[i] - wsp[i+1]));
        events.PB(E(2, i, tree.best[i] - wsp[i]));
    }
    FOR(i,1,m)
        events.PB(E(3, i, q[i]));
    sort(ALL(events));
    FORE(e,events) {
//        cout << "e " << e->co << " " << e->kto << " " << e->kiedy << endl;
        if(e->co == 1) {
            kor++;
            sum -= e->kiedy;
        } else if(e->co == 2) {
            kor--;
            sum += e->kiedy;
        } else if(e->co == 3) {
            ans[e->kto] = sum + e->kiedy * kor;
        }
    }
	//out
    FOR(i,1,m) cout << ans[i] << " ";
    cout << endl;
	return 0;
}