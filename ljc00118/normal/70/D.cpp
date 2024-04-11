#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

struct Point {
    int x, y;
    Point (int a = 0, int b = 0) : x(a), y(b) {}

    bool operator < (const Point A) const { return (x ^ A.x) ? (x < A.x) : (y < A.y); }
};

Point operator - (const Point a, const Point b) { return Point(a.x - b.x, a.y - b.y); }

set <Point> up, down;
set <Point> :: iterator it, itl, itr, tmp;
int n;

ll Cross(Point a, Point b) { return (ll)a.x * b.y - (ll)a.y * b.x; }

ll Area2(Point a, Point b, Point c) { return Cross(b - a, c - a); }

bool check1(Point now) {
    itl = itr = up.lower_bound(now);
    if(itl == up.begin() || itl == up.end()) return 0;
    --itl;
    if(Area2(*itl, now, *itr) < 0) return 0;
    return 1;
}

bool check2(Point now) {
    itl = itr = down.lower_bound(now);
    if(itl == down.begin() || itl == down.end()) return 0;
    --itl;
    if(Area2(*itl, now, *itr) > 0) return 0;
    return 1;
}

bool check(Point now) { return check1(now) && check2(now); }

int main() {
    read(n);
    while(n--) {
        int opt, x, y;
        read(opt); read(x); read(y);
        if(opt == 1) {
            if(up.find(Point(x, y)) != up.end() || down.find(Point(x, y)) != down.end()) continue;
            if(!check1(Point(x, y))) {
                it = itl = itr = up.insert(Point(x, y)).first;
                while(1) {
                    if(it == up.begin()) { break; } itr = it; --itr;
                    if(itr == up.begin()) { break; } itl = itr; --itl;
                    if(Cross(*itr - *itl, *it - *itl) >= 0) up.erase(itr); else break;
                }
                while(1) {
                    tmp = up.end(); --tmp;
                    if(it == tmp) { break; } itl = it; ++itl;
                    if(itl == tmp) { break; } itr = itl; ++itr;
                    if(Cross(*itl - *it, *itr - *it) >= 0) up.erase(itl); else break;
                }
            }
            if(!check2(Point(x, y))) {
                it = itl = itr = down.insert(Point(x, y)).first;
                while(1) {
                    if(it == down.begin()) { break; } itr = it; --itr;
                    if(itr == down.begin()) { break; } itl = itr; --itl;
                    if(Cross(*itr - *itl, *it - *itl) <= 0) down.erase(itr); else break;
                }
                while(1) {
                    tmp = down.end(); --tmp;
                    if(it == tmp) { break; } itl = it; ++itl;
                    if(itl == tmp) { break; } itr = itl; ++itr;
                    if(Cross(*itl - *it, *itr - *it) <= 0) down.erase(itl); else break;
                }
            }
        }
        // fprintf(stderr, "up : ");
        // for(it = up.begin(); it != up.end(); ++it) fprintf(stderr, "{%d, %d}, ", it -> x, it -> y);
        // fprintf(stderr, "\n");
        // fprintf(stderr, "down : ");
        // for(it = down.begin(); it != down.end(); ++it) fprintf(stderr, "{%d, %d}, ", it -> x, it -> y);
        // fprintf(stderr, "\n");
        if(opt == 2) {
            if(up.find(Point(x, y)) != up.end() || down.find(Point(x, y)) != down.end()) printf("YES\n");
            else if(check(Point(x, y))) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}