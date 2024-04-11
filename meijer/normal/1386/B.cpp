#include <bits/stdc++.h>
using namespace std;

//macros
typedef __int128 ll;
typedef double ld;
typedef pair<int, int> ii;
typedef pair<ll, ll> lll;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
typedef vector<lll> vlll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define EPS 1e-9
#define pb push_back
#define fi first
#define se second
#define sz size()

//===================//
//  Added libraries  //
//===================//

// geometry library
ll gcd(ll a, ll b) {return b==0?a:gcd(b,a%b);}
struct Vec {
    ll x, y;
    Vec operator+ (Vec rs) {
        Vec res;
        res.x = x + rs.x;
        res.y = y + rs.y;
        return res;
    }
    Vec operator- (Vec rs) {
        Vec res;
        res.x = x - rs.x;
        res.y = y - rs.y;
        return res;
    }
    bool operator== (Vec rs) {
        return x==rs.x && y==rs.y;
    }
};

struct LineSeg { // line seg from a -> b
    Vec a, b;
};
struct Triangle {
    Vec p[3];
};

ll dot(Vec a, Vec b) {return a.x*b.x + a.y*b.y;}
ll norm(Vec a) {return a.x*a.x + a.y*a.y;}
ll cross(Vec a, Vec b) {return a.x*b.y - a.y*b.x;}
bool ccw(LineSeg l, Vec p) { // returns true if p is on the left side of l (a -> b)
    return cross(l.b-l.a, p-l.a) > 0;
}
bool collinear(Vec a, Vec b, Vec c) { // returns true if p is on the same line as the lineseg l is on (a -> b)
    return cross(b-a, c-a) == 0;
}
struct CompAngle {
    bool operator()(const Vec& a, const Vec& b) const {
        if(a.y < 0 || (a.y == 0 && a.x < 0)) {
            if(!(b.y < 0 || (b.y == 0 && b.x < 0))) return 1;
        } else {
            if(b.y < 0 || (b.y == 0 && b.x < 0)) return 0;
        }
        return cross(a, b) > 0;
    }
};

//===================//
//end added libraries//
//===================//

void program();
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    program();
}


//===================//
//   begin program   //
//===================//

const int MX = 2e5;
long long A[3], B[3];
ll C[3];
int n, m=0;
Vec points[MX];
set<Vec, CompAngle> angles;
map<Vec, int, CompAngle> angleCount;
int inCent=0, cntOp=0, cnt180=0;

auto getPrev(Vec a) {
    auto it = angles.lower_bound(a);
    if(it == angles.begin()) return --angles.end();
    return --it;
}
auto getNext(Vec a) {
    auto it = angles.upper_bound(a);
    if(it == angles.end()) return angles.begin();
    return it;
}
void addAngle(Vec a) {
    if(angleCount[a]++ != 0) return;

    if(angles.sz == 0) {
        cnt180 = 0;
    } else {
        auto pre = getPrev(a);
        auto nxt = getNext(a);
        ll cr = cross(*pre, *nxt);
        if(pre != nxt && cr < 0) cnt180--;
        cr = cross(*pre, a);
        if(cr < 0) cnt180++;
        cr = cross(a, *nxt);
        if(cr < 0) cnt180++;
    }

    angles.insert(a);

    Vec op = {-a.x, -a.y};
    if(angles.count(op)) cntOp++;
}
void removeAngle(Vec a) {
    if(angleCount[a]-- != 1) return;
    angles.erase(a);

    Vec op = {-a.x, -a.y};
    if(angles.count(op)) cntOp--;

    if(angles.sz == 0) {
        cnt180 = 0;
    } else {
        auto pre = getPrev(a);
        auto nxt = getNext(a);
        ll cr = cross(*pre, *nxt);
        if(pre != nxt && cr < 0) cnt180++;
        cr = cross(*pre, a);
        if(cr < 0) cnt180--;
        cr = cross(a, *nxt);
        if(cr < 0) cnt180--;
    }
}

void program() {
    RE(i,3) cin>>A[i];

    cin>>n;
    RE1(QueryNumber,n) {
        char c; cin>>c;
        if(c == 'A') {
            RE(i,3) cin>>B[i];
            RE(i,3) C[i] = B[i]*(A[0]+A[1]+A[2]) - A[i]*(B[0]+B[1]+B[2]);
            ll GCD = gcd(C[0]<0 ? -C[0] : C[0], C[1]<0 ? -C[1] : C[1]);
            if(GCD != 0) C[0]/=GCD, C[1]/=GCD;
            points[++m] = {C[0],  C[1]};
            Vec a = points[m];
            if(a.x == 0 && a.y == 0) inCent++;
            else addAngle(a);
        } else {
            int x;
            cin>>x;
            Vec a = points[x];
            if(a.x == 0 && a.y == 0) inCent--;
            else removeAngle(a);
        }
        int ans = 4;
        if(inCent) ans = 1;
        if(ans == 4 && cntOp) ans = 2;
        if(ans == 4 && angles.size()>=3 && cnt180==0) ans = 3;
        if(ans == 4) ans = 0;
        printf("%d\n", ans);
    }
}