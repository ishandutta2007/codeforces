#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = double;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

#define fastAllocatorMemory 200'000'000

#ifdef fastAllocatorMemory
int allocatorPos = 0;
char allocatorMemory[int(fastAllocatorMemory)];
inline void* operator new (size_t n) {
    char* res = allocatorMemory + allocatorPos;
    allocatorPos += n;
    return (void*)res;
}
inline void operator delete (void*) noexcept {}
#endif


struct point {
    int x, y;
    point() {}
    point(int x, int y) : x(x), y(y) {}
    ll operator % (point p) {
        return 1ll * x * p.y - 1ll * y * p.x;
    }
    inline int where() {
        assert(!(x == 0 && y == 0));
        if (x == 0)
            return y > 0 ? 2 : 4;
        if (y == 0)
            return x > 0 ? 1 : 3;
        if (x > 0)
            return y > 0 ? 1 : 4;
        return y > 0 ? 2 : 3;
    }
    bool operator < (point p) {
        int wa = where(), wb = p.where();
        if (wa != wb)
            return wa < wb;
        return *this % p > 0;
    }
    inline ld size() {
        return sqrt(1ll * x * x + 1ll * y * y);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout << fixed << setprecision(10);

    int n, k;
    cin >> n >> k;
    vec<point> p(n);
    int id = -1;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        if (p[i].x == 0 && p[i].y == 0)
            id = i;
    }
    assert(id != -1);
    p.erase(p.begin() + id);
    n--;

    sort(all(p));
    vec<vec<point>> groups;
    for (int i = 0; i < n;) {
        groups.push_back({p[i]});
        for (i++; i < n && !(p[i - 1] < p[i]); i++)
            groups.back().push_back(p[i]);
    }

    int g = len(groups);
    vec<ld> vals;
    vec<ld> sum_dist(g), sum_vals(g);
    vec<vec<ld>> cur_vals(g);
    ld tot_sum_vals = 0;
    ld tot_sum_dist = 0;

    int need = (k + 1) / 2;
    for (int i = 0; i < g; i++) {
        sort(all(groups[i]), [&](point a, point b) {
            return a.size() < b.size();
        });
        cur_vals[i].resize(len(groups[i]));
        for (int j = len(groups[i]) - 1; j >= 0; j--) {
            ld dist = groups[i][j].size();
            int cnt = len(groups[i]) - j - 1;
            ld cur_val = dist * (k - 1 - cnt - cnt);
            vals.push_back(cur_val);
            sum_dist[i] += dist;
            sum_vals[i] += cur_val;
            cur_vals[i][j] = cur_val;
        }
        tot_sum_dist += sum_dist[i];
        tot_sum_vals += sum_vals[i];
    }

    sort(all(vals));
    reverse(all(vals));
    ld ans = 0;
    for (int i = 0; i < min(k, len(vals)); i++)
        ans += vals[i];
    if (k > n) {
        cout << ans << '\n';
        return 0;
    }

    for (int i = 0; i < g; i++) 
        if (len(groups[i]) >= need) {
            int another = n + 1 - len(groups[i]);
            int left = k - need;
            if (another <= left) {
                ld cur = tot_sum_vals - sum_vals[i];
                ld cur_sum_dist = 0;
                for (int j = len(groups[i]) - 1; j >= len(groups[i]) - need; j--) {
                    ld dist = groups[i][j].size();
                    int cnt = len(groups[i]) - j - 1;
                    cur += cur_sum_dist - cnt * dist;
                    cur_sum_dist += dist;
                }
                cur += cur_sum_dist * another;
                left -= another;
                assert(left + need <= len(groups[i]));
                ld sub = 0;
                for (int j = 0; j < left; j++) {
                    ld dist = groups[i][j].size();
                    cur += dist * j - sub;
                    cur += dist * another;
                    cur += cur_sum_dist - need * dist;
                    sub += dist;
                }
                ans = max(ans, cur);
            }
        }
    cout << ans << '\n';
}