#include <bits/stdc++.h>
using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair <ld, ld> ldld;
typedef pair <ld, int> ldi;

const int Maxn = 20005;
const ld eps = 1e-14l;
const ld pi = acos(-1.0l);

int n, d;
vector <ldld> seq;
vector <ldi> ans;

ld Len(ld ax, ld ay) { return sqrt(ax * ax + ay * ay); }

void Intersect(ll x1, ll y1, ll r1, ll x2, ll y2, ll r2)
{
	ld d = Len(x1 - x2, y1 - y2);
	if (r1 + r2 + eps < d) return;
	if (min(r1, r2) + d + eps < max(r1, r2)) return;
	if (fabs(d) < eps) return;
	ld a = (r1 * r1 - r2 * r2 + d * d) / (2.0l * d);
	ld h = sqrt(r1 * r1 - a * a);
	ld px = x1 + (x2 - x1) / d * a;
	ld py = y1 + (y2 - y1) / d * a;
	ldld res1 = ldld(px + (y2 - y1) / d * h, py + (x1 - x2) / d * h);
	ldld res2 = ldld(px + (y1 - y2) / d * h, py + (x2 - x1) / d * h);
	seq.push_back(res1);
	seq.push_back(res2);
}

ld Cross(const ldld &a, const ldld &b)
{
    return a.first * b.second - a.second * b.first;
}


int main()
{
    scanf("%d %d", &n, &d);
    for (int i = 0; i < n; i++) {
        int x, y, r; scanf("%d %d %d", &x, &y, &r);
        int from = (sqrt(ld(x * x + y * y)) - r) / d;
        int to = (sqrt(ld(x * x + y * y)) + r) / d + 1;
        if (from < 1) from = 1;
        bool was = false;
        ldld lef, rig;
        for (int i = from; i <= to; i++) {
            seq.clear();
            Intersect(0, 0, d * i, x, y, r);
            if (seq.empty()) continue;
            if (seq.size() == 2 && Cross(seq[0], seq[1]) < 0)
                swap(seq[0], seq[1]);
            ld L = atan2(seq[0].second, seq[0].first);
            ld R = atan2(seq.back().second, seq.back().first);
            if (L <= R) {
                ans.push_back(ldi(L - eps, 1));
                ans.push_back(ldi(R, -1));
            } else {
                ans.push_back(ldi(L - eps, 1));
                ans.push_back(ldi(pi, -1));
                ans.push_back(ldi(-pi - eps, 1));
                ans.push_back(ldi(R, -1));
            }
        }
    }
    sort(ans.begin(), ans.end());
    int res = 0, st = 0;
    for (int i = 0; i < ans.size(); i++) {
        st += ans[i].second;
        res = max(res, st);
    }
    printf("%d\n", res);
    return 0;
}