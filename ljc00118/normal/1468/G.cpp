#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

// orz Itst
#define ld long double
#define eps 1e-10
bool cmp0(ld x){return fabs(x) < eps;}
struct vec{
    ld x , y; vec(ld _x = 0 , ld _y = 0) : x(_x) , y(_y){}
    friend vec operator +(vec p , vec q){return vec(p.x + q.x , p.y + q.y);}
    friend vec operator -(vec p , vec q){return vec(p.x - q.x , p.y - q.y);}
    friend vec operator *(vec p , ld q){return vec(p.x * q , p.y * q);}
    friend ld operator *(vec p , vec q){return p.x * q.x + p.y * q.y;}
    friend ld operator %(vec p , vec q){return p.x * q.y - p.y * q.x;}
    friend ld ang(vec p){return atan2(p.y , p.x);}
    friend ld len(vec p){return sqrt(p.x * p.x + p.y * p.y);}
    friend vec rot(vec p , ld Cos , ld Sin){return vec(p.x * Cos - p.y * Sin , p.x * Sin + p.y * Cos);}
    friend bool operator <(vec p , vec q){return cmp0(p.x - q.x) ? (cmp0(p.y - q.y) ? 0 : p.y < q.y) : p.x < q.x;}
    friend bool operator ==(vec p , vec q){return !(p < q) && !(q < p);}
    void input(){cin >> x >> y;}
};

struct line{
    vec s , t; line(vec _s = vec() , vec _t = vec()) : s(_s) , t(_t){}
    friend ld len(line p){return len(p.t - p.s);}
    friend ld ang(line p){return ang(p.t - p.s);}
    friend vec sect(line p , line q){
        if(cmp0((p.t - p.s) % (q.t - q.s))) return vec(-1e60);
        ld scale = ((p.t - q.s) % (q.t - q.s)) / ((p.t - p.s) % (q.t - q.s)); if(scale < -eps || scale > 1 + eps) return vec(-1e60);
        vec ans = p.t + (p.s - p.t) * scale;
        return ans;
    }
    void input(){s.input(); t.input();}
    ld val(ld p){return s.y + (p - s.x) / (t.x - s.x) * (t.y - s.y);}
    friend bool operator <(line p , line q){
        ld x = max(p.s.x , q.s.x) , vp = p.val(x) , vq = q.val(x);
        if(!cmp0(vp - vq)) return vp < vq;
        x = min(p.t.x , q.t.x); vp = p.val(x); vq = q.val(x); return vp < vq;
    }
};

const int N = 2e5 + 5;

vec a[N];
int n, H;

ld cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

void debug(vec a) {
    fprintf(stderr, "{%.10lf, %.10lf}\n", (double)a.x, (double)a.y);
}

int main() {
    read(n); read(H);
    for (int i = 1; i <= n; i++) {
        int x, y;
        read(x); read(y);
        a[i].x = x; a[i].y = y;
    }
    vec las = a[n], eye = a[n] + vec(0, H);
    ld ans = 0;
    for (int i = n - 1; i >= 1; i--) {
        vec now = a[i + 1] - a[i], h = eye - las;
        // fprintf(stderr, "debug : %.10lf\n", (double)cross(h, now));
        if (cmp0(cross(h, now)) && cmp0(cross(eye - a[i], a[i + 1] - a[i]))) {
            ans += len(now);
            continue;
        }
        if (cross(h, now) > 0) continue;
        line x = line(a[i], a[i + 1]), y = line(las, eye);
        // debug(a[i]); debug(a[i + 1]); debug(las); debug(eye);
        vec po = sect(x, y);
        if (po.x < a[i].x) continue;
        // fprintf(stderr, "i = %d, po.x = %.10lf, po.y = %.10lf\n", i, (double)po.x, (double)po.y);
        ans += len(a[i] - po); las = a[i];
    }
    printf("%.10lf\n", (double)ans);
    return 0;
}