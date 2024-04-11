#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>
#include <cmath>
#define f first
#define s second
using namespace std;

typedef long double ld;
typedef pair <ld, ld> pnt;

const int Maxn = 300;
const ld sm = 0.0001;

int n;
pair <pnt, pnt> seg[Maxn];
set <pnt> dots[Maxn];
ld ans;

ld LL(const pair <pnt, pnt> &p)
{
    return sqrt((p.f.f - p.s.f) * (p.f.f - p.s.f) + (p.f.s - p.s.s) * (p.f.s - p.s.s));
}

ld TP(ld a, ld b, ld c)
{
    ld p = (a + b + c) / 2;
    return sqrt(p) * sqrt(p - a) * sqrt(p - b) * sqrt(p - c);
}

bool isIn(ld x, ld y, int num)
{
     pair <ld, ld> p = make_pair(x, y);
     ld s = TP(LL(seg[3*num]), LL(seg[3*num+1]), LL(seg[3*num+2]));
     ld s1 = TP(LL(seg[3*num]), LL(make_pair(p, seg[3*num].f)),
                                LL(make_pair(p, seg[3*num].s)));
     ld s2 = TP(LL(seg[3*num+1]), LL(make_pair(p, seg[3*num+1].f)),
                                  LL(make_pair(p, seg[3*num+1].s)));
     ld s3 = TP(LL(seg[3*num+2]), LL(make_pair(p, seg[3*num+2].f)),
                                  LL(make_pair(p, seg[3*num+2].s)));
     return fabs(s - s1 - s2 - s3) < sm;
}

int main()
{
    ld p[6], num, den, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) cin >> p[j];
        seg[3*i] = make_pair(make_pair(p[0], p[1]), make_pair(p[2], p[3]));
        dots[3*i].insert(make_pair(p[0], p[1])); dots[3*i].insert(make_pair(p[2], p[3]));
        seg[3*i+1] = make_pair(make_pair(p[0], p[1]), make_pair(p[4], p[5]));
        dots[3*i+1].insert(make_pair(p[0], p[1])); dots[3*i+1].insert(make_pair(p[4], p[5]));
        seg[3*i+2] = make_pair(make_pair(p[2], p[3]), make_pair(p[4], p[5]));
        dots[3*i+2].insert(make_pair(p[2], p[3])); dots[3*i+2].insert(make_pair(p[4], p[5]));
    }
    for (int i = 0; i < 3*n; i++)
       for (int j = 0; j < 3*n; j++) {
           ld num, den;
           num = (seg[j].f.f - seg[i].f.f) * (seg[i].s.s - seg[i].f.s) -
                 (seg[j].f.s - seg[i].f.s) * (seg[i].s.f - seg[i].f.f);
           den = (seg[i].s.f - seg[i].f.f) * (seg[j].s.s - seg[j].f.s) -
                 (seg[i].s.s - seg[i].f.s) * (seg[j].s.f - seg[j].f.f);
           if (fabs(den) < sm) continue;
           b = num / den;
           if (b < 0 || b > 1) continue;
           num = seg[j].f.f - seg[i].f.f + (seg[j].s.f - seg[j].f.f) * b;
           den = seg[i].s.f - seg[i].f.f;
           if (fabs(den) < sm) continue;
           a = num / den;
           if (a < 0 || a > 1) continue;
           dots[i].insert(make_pair(seg[i].f.f + (seg[i].s.f - seg[i].f.f) * a,
                                    seg[i].f.s + (seg[i].s.s - seg[i].f.s) * a));
           dots[j].insert(make_pair(seg[i].f.f + (seg[i].s.f - seg[i].f.f) * a,
                                    seg[i].f.s + (seg[i].s.s - seg[i].f.s) * a));
       }
    for (int i = 0; i < 3*n; i++) {
        set <pnt>::iterator lit, it;
        it = dots[i].begin(); lit = it++;
        for (; it != dots[i].end(); lit++, it++) {
            a = (lit->f + it->f) / 2.; b = (lit->s + it->s) / 2.;
            int j;
            for (j = 0; j < n; j++) if (j != i / 3)
               if (isIn(a, b, j)) break;
            if (j == n) ans += sqrt((it->f - lit->f) * (it->f - lit->f) + 
                                    (it->s - lit->s) * (it->s - lit->s));
        }
    }
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}