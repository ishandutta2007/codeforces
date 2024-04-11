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
typedef pair<LL, LL>P;
typedef pair<LL, P> PP;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN (1<<18)
#define ILE X
#define PREF Y.X
#define SUM Y.Y

LL n, xx[MAXN], act[MAXN], m, t[MAXN];
vector<LL> wsp;

PP join(PP A,PP B){
    return PP(A.ILE+B.ILE, P(A.PREF+B.PREF, A.SUM+B.SUM+B.PREF*A.ILE-A.PREF*B.ILE));
}

struct Tree{
    LL is[2*MAXN];
    PP dp[2*MAXN];

    void add(int a, int val, int x=1, int ll=1, int rr=MAXN) {
//        if(x == 1) cout << "add " << a << " " << val << endl;
        if(a < ll || rr < a) return;
        if(ll == rr) {
            is[x] += val;
            dp[x] = (is[x] ? PP(1,P(wsp[ll-1],0)) : PP(0,P(0,0)));
            return;
        }
        add(a,val,2*x,ll,(ll+rr)/2);
        add(a,val,2*x+1,(ll+rr+1)/2,rr);
        dp[x] = join(dp[2*x], dp[2*x+1]);
//        cout << "ile " << x << " " << dp[x].ILE << endl;
    }

    PP get(int l, int r, int x=1, int ll=1, int rr=MAXN) {
//        if(x == 1) cout << "get " << l << "-" << r << endl;
        if(r < ll || rr < l) return PP(0,P(0,0));
        if(l <= ll && rr <= r) return dp[x];
        return join(get(l,r,2*x,ll,(ll+rr)/2), 
                get(l,r,2*x+1,(ll+rr+1)/2,rr));
    }
};

Tree tree;
LL l[MAXN],r[MAXN];

LL nr(LL x) {
        return lower_bound(ALL(wsp), x) - wsp.begin() + 1;
}
int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n;
    FOR(i,1,n) cin >> xx[i];
    cin >> m;
    FOR(i,1,m) cin >> t[i] >> l[i] >> r[i];
    //wsp
    wsp.PB(2E9);
    wsp.PB(-2E9);
    FOR(i,1,n) {
        act[i] = xx[i];
        wsp.PB(act[i]);
    }
    FOR(i,1,m) if(t[i] == 1)
        wsp.PB(act[l[i]] += r[i]);
    sort(ALL(wsp));
    wsp.erase(unique(ALL(wsp)),wsp.end());
	//sol
    FOR(i,1,n) {
        act[i] = xx[i];
        tree.add(nr(xx[i]),1);
    }
//    cout << tree.dp[1].ILE << "!!!" << endl;
    FOR(i,1,m) if(t[i] == 1) {
        int old = nr(act[l[i]]);
        act[l[i]] += r[i];
        int next = nr(act[l[i]]);
        tree.add(old, -1);
        tree.add(next, 1);
    } else {
        int a = nr(l[i]);
        int b = nr(r[i]);
        if(wsp[b-1] > r[i]) b--;
        LL res = 0;
//        cout << a << "-" << b << endl;
        if(a<=b) {
//            PP pp = tree.get(a,b);
//            cout << pp.ILE << " pref " << pp.PREF << " s" << pp.SUM << endl;
            res = tree.get(a,b).SUM;
        }
        cout << res << endl;
    }
	//out
	return 0;
}