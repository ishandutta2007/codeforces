#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
static char ibuf[1 << 20]; char *fis = ibuf, *fit = ibuf;
inline char readChar() { return fis == fit && (fit = (fis = ibuf) + fread(ibuf, 1, 1 << 20, stdin), fis == fit) ? EOF : *fis++; }
inline int read() {
    char c, _c; int x; for (c = readChar(); !isdigit(c); c = readChar());
    for (x = 0; isdigit(c); c = readChar()) { x = x * 10 + c - '0'; } return x;
}
static char ostc[100], obuf[1 << 20]; int ol = 0; char *fos = obuf, *fot = obuf + (1 << 20) - 1;
inline void writeChar(char c) { *fos++ = c; if (fos == fot) { fwrite(obuf, 1, fos - obuf, stdout); fos = obuf; } }
inline void write(int n, char c) {
    if (!n) { writeChar('0'); } else { while (n) { ostc[++ol] = n % 10 + 48, n /= 10; } }
    for (; ol; ol--) { writeChar(ostc[ol]); } writeChar(c);
}
const int N = 200010;
const double eps = 1e-8;
const double pi = acos(-1.0);
int n, k;
pii a[N];

double turn(pii x) 
{
    double ang = atan2(x.Y, x.X);
    if (ang < 0) ang += 2 * pi;
    return ang;
}
 
double dist(pii x) 
{
    return sqrt(1.0 * x.X * x.X + 1.0 * x.Y * x.Y);
} 

bool check(double r)
{
    //cout << r << endl;
    vector<pair<double, double> > v;
    int cnt = 0;
    rep(i, 1, n)
    {
        double x = a[i].X;
        double y = a[i].Y;
        if(x == 0 && y == 0) {cnt ++; continue;}
        double d = dist(a[i]);
        if (d + eps > 2 * r) continue;
        double ang = acos(d / (2.0 * r));
        double pol = turn(a[i]);
        double a1 = pol - ang, a2 = pol + ang;
        if (a1 < 0) a1 += 2 * pi;
        if (a2 > 2 * pi) a2 -= 2 * pi;
        if (a1 < a2) v.pb(mp(a1 - eps, a2 + eps));
        else v.pb(mp(a1 - eps, 2 * pi + eps)), v.pb(mp(0 - eps, a2 + eps));
    }
    vector<pair<double, int> > pts;
    for (auto el : v) pts.pb(mp(el.X, 0)), pts.pb(mp(el.Y, 1));
    sort(ALL(pts));
    if (cnt >= k)  return 1;
    for (auto el : pts)
    {
        if (el.Y == 0) cnt ++;
        else cnt --;
        if (cnt >= k) return 1;
    }
    return 0;
}
 

int main()
{
    scanf("%d%d", &n, &k);
    rep(i, 1, n)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        a[i] = mp(x, y);
    }
    double l = 0.0, r = 200000, epss = 1e-5;
    while(fabs(r - l) > epss)
    {
        double mid = (l + r) / 2.0;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%.10f", l);
    return 0;
}