#define all(v) v.begin(), v.end()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(v) (int(v.size()))
#define pch putchar
#define gch getchar()
#define FORD(i,a,b) for (int i=(a); i<=(b); i++)
#define FORP(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define clean(v) memset(v,0,sizeof(v))

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

template<typename T> T sqr(const T& c) {return c*c;} 

typedef long long ll;
typedef double lf;

ll x[6], y[6];

ll dist(int p1, int p2) {
    return sqr(p1[x]-p2[x])+sqr(p1[y]-p2[y]);
}

bool belong(int p, int p1, int p2) {
    //cerr << p << ' ' << p1 << ' ' << p2 << '\n';
    ll x1 = x[p1] - x[p], y1 = y[p1] - y[p];
    ll x2 = x[p2] - x[p], y2 = y[p2] - y[p];
    return x1*x2+y1*y2<0 && x1*y2-x2*y1==0;
}

bool ok(int p1, int p2, int p3) {
    bool f = 0; ll vx1, vy1, vx2, vy2;
    FORD(i,2*p1,2*p1+1) FORD(j,2*p2,2*p2+1) if (x[i]==x[j] && y[i]==y[j]) {
        f = 1;
        vx1 = x[i^1]-x[i], vy1 = y[i^1]-y[i];
        vx2 = x[j^1]-x[j], vy2 = y[j^1]-y[j];
        break;  
    }
    if (!f) return 0;
    //cerr << vx1 << ' ' << vy1 << '\n';
    //cerr << vx2 << ' ' << vy2 << '\n';
    if (vx1*vy1-vx2*vy2==0 || vx1*vx2+vy1*vy2<0) return 0;
    //cerr << "!";
    f = 0;
    if (belong(2*p3,2*p1,2*p1+1) && belong(2*p3+1,2*p2,2*p2+1)) {
        //cerr << "!";
        ll d1 = dist(2*p3,2*p1), d2 = dist(2*p3,2*p1+1);
        if (d1>d2*16 || d2>d1*16) return 0;
        d1 = dist(2*p3+1,2*p2), d2 = dist(2*p3+1,2*p2+1);
        if (d1>d2*16 || d2>d1*16) return 0;
        return 1;
    }
    if (belong(2*p3+1,2*p1,2*p1+1) && belong(2*p3,2*p2,2*p2+1)) {
        //cerr << "!";
        ll d1 = dist(2*p3+1,2*p1), d2 = dist(2*p3+1,2*p1+1);
        //cerr << d1 << ' ' << d2;
        if (d1>d2*16 || d2>d1*16) return 0;
        d1 = dist(2*p3,2*p2), d2 = dist(2*p3,2*p2+1);
        if (d1>d2*16 || d2>d1*16) return 0;
        return 1;
    }
    return 0;
}

void solve() {
    REP(i,6) scanf("%I64d%I64d",&x[i],&y[i]);
    puts(ok(0,1,2) || ok(0,2,1) || ok(1,2,0)?"YES":"NO");
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    REP(i,n) solve();
}