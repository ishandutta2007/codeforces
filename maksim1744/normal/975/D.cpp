#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

long long a, b, n;

struct ghost
{
    long long x0, y0, vx, vy, v, far_v, line_v;
    ghost(long long x, long long vxx, long long vyy)
    {
        x0 = x;
        y0 = x * a + b;
        vx = vxx;
        vy = vyy;
        v = vx * vx + vy * vy;
        far_v = a * vx - vy;
        line_v = vx + a * vy;
    }
};

bool comp_by_mod_v(ghost a, ghost b)
{
    if (a.v == b.v) {
        return a.vx < b.vx;
    }
    return a.v < b.v;
}

bool comp_by_far_v(ghost a, ghost b)
{
    if (a.far_v != b.far_v) {
        return a.far_v < b.far_v;
    }
    return a.line_v < b.line_v;
}

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    int t = 3;
    if (!debug) {
        t = 1;
    }
    for (int test = 0; test < t; ++test)
    {
        if (debug) {
            cout << "Case #" << test + 1 << ":\n";
        }
        vector< ghost > line;
        vector< ghost > v;
        cin >> n >> a >> b;
        for (int i = 0; i < n; ++i)
        {
            long long x, vx, vy;
            cin >> x >> vx >> vy;
            if (vy == vx * a) {
                line.push_back(ghost(x, vx, vy));
            }
            else {
                v.push_back(ghost(x, vx, vy));
            }
        }
        long long sm = 0;
        if (line.size() > 1) {
            sort(line.begin(), line.end(), comp_by_mod_v);
            long long sz = line.size();
            sm += (sz - 1) * sz;
            long long i1 = 0, i2 = 0;
            while (i1 < sz) {
                i2 = i1;
                while (i2 < sz && line[i1].vx == line[i2].vx) {
                    i2++;
                }
                long long d = i2 - i1;
                sm -= d * (d - 1);
                i1 = i2;
            }
        }
        sort(v.begin(), v.end(), comp_by_far_v);
        long long i1 = 0, i2 = 0;
        long long sz = v.size();
        while (i1 < sz) {
            i2 = i1;
            while (v[i1].far_v == v[i2].far_v) {
                i2++;
            }
            long long d = i2 - i1;
            sm += d * (d - 1);
            long long j1 = i1, j2 = i1;
            while (j1 < i2) {
                j2 = j1;
                while (v[j1].line_v == v[j2].line_v) {
                    j2++;
                }
                d = j2 - j1;
                sm -= d * (d - 1);
                j1 = j2;
            }
            i1 = i2;
        }
        cout << sm << '\n';
    }
    fclose(stdout);
    return 0;
}