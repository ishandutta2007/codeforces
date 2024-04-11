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
typedef pair<int, P>PP;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }
#define MAXN 100007

struct MSS {
    PP mss, left, right, sum;
    MSS(int x, int p) {
        sum = PP(x,P(p,p));
        left = right = mss = (x > 0 ? PP(x,P(p,p)) : PP(0,P(0,0)));
    }
    MSS() {
        MSS(0,0);
    }
    void out() {
        cout << "MSS sum " << sum.X << " l " << left.X << " r " << right.X << " mss " << mss.X << endl;
    }
};

inline PP operator+(PP a, PP b) {
    if(a.Y.X == 0) return b;
    if(b.Y.X == 0) return a;
    return PP(a.X+b.X, P(min(a.Y.X, b.Y.X), max(a.Y.Y, b.Y.Y)));
}

inline MSS join(MSS a, MSS b) {
    MSS r(0,0);
    r.sum = a.sum + b.sum;
    r.left = max(a.left, a.sum + b.left);
    r.right = max(b.right, b.sum + a.right);
    r.mss = max(a.right + b.left, max(a.mss, b.mss));
    return r;
}

#define BASE (1<<17)
struct DP {
    MSS dp[2*BASE][2];
    bool rev[2*BASE];
    DP(){CLR(dp); CLR(rev);}

inline void prepare(int x) {
            if(rev[x]) {
                swap(dp[x][0], dp[x][1]);
                if(x < BASE) {
                    rev[x+x] ^= 1;
                    rev[x+x+1] ^= 1;
                }
                rev[x] = 0;
            }
}

inline void update(int x) {
            REP(i,2) dp[x][i] = join(dp[x+x][i], dp[x+x+1][i]);
}

    void set(int l, int r, int v, int x = 1, int ll = 1, int rr = BASE) {
        prepare(x);
        if(r < ll || rr < l) return;
        if(l <= ll && rr <= r) { //przedzial basowy
            dp[x][0] = MSS(v,l);
            dp[x][1] = MSS(-v,l);
        } else { //nadprzedzial
            set(l, r, v, x+x, ll, (ll+rr)/2);
            set(l, r, v, x+x+1, (ll+rr+1)/2, rr);
            //update
            update(x);
        }
    }

    MSS get(int l, int r, int x = 1, int ll = 1, int rr = BASE) {
        prepare(x);
        if(r < ll || rr < l) return MSS(0,0);
        if(l <= ll && rr <= r) { //przedzial basowy
            return dp[x][0];
        } else { //nadprzedzial
            return join(get(l, r, x+x, ll, (ll+rr)/2), 
                        get(l, r, x+x+1, (ll+rr+1)/2, rr));
        }
    }

    void swapy(int l, int r, int x = 1, int ll = 1, int rr = BASE) {
        prepare(x);
        if(r < ll || rr < l) return;
        if(l <= ll && rr <= r) { //przedzial basowy
            rev[x] ^= 1;
            prepare(x);
        } else { //nadprzedzial
            swapy(l, r, x+x, ll, (ll+rr)/2);
            swapy(l, r, x+x+1, (ll+rr+1)/2, rr);
            //update
            update(x);
        }
       /* if(x == 1) {
            cout << "swap " << l << "-" << r << endl;
            dp[1][0].out();
            dp[1][1].out();
        } */
    }

    int get_ans(int l, int r, int k) {
        vector<P> swapped;
        int res = 0;
        REP(i,k) {
            PP mss = get(l, r).mss;
            res += mss.X;
            if(mss.Y.X != 0) {
                swapped.PB(mss.Y);
                swapy(mss.Y.X, mss.Y.Y);
            }
        }
        FORE(i, swapped)
            swapy(i->X, i->Y);
        return res;
    }
};

DP dp;
int n,m;

int main(){
	ios_base::sync_with_stdio(false);
    cout << setprecision(15) << fixed;
	//in
    cin >> n;
    FOR(i,1,n) {
        int x;
        cin >> x;
        dp.set(i,i,x);
    }
	//sol
    cin >> m;
    while(m--) {
        int t;
        cin >> t;
        if(t == 0) {
            int i, val;
            cin >> i >> val;
            dp.set(i,i,val);
        } else {
            int l, r, k;
            cin >> l >> r >> k;
            cout << dp.get_ans(l, r, k) << endl;
        }
    }
	return 0;
}