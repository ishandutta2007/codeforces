#include <cstdio>
#include <vector>

using namespace std;

const int N = 2222222;

int h[N], v[N];

int main() {
    int t;
    scanf("%d", &t);
    for (int cs = 1; cs <= t; ++cs) {
        int n;
        scanf("%d", &n);
        vector<int> c;
        for (int i = 1; i <= n; ++i) {
            int x;
            scanf("%d", &x);
            if (v[x] != cs) {
                v[x] = cs;
                c.push_back(x);
                h[x] = 1;
            } else {
                ++h[x];
            }
        }
        int l = h[c[0]];
        for (int i = 1; i < c.size(); ++i) {
            if (h[c[i]] < l) {
                l = h[c[i]];
            }
        }
        int ans = N;
        for (int s = 1; s <= l + 1; ++s) {
            bool f = true;
            int cur = 0;
            for (int i = 0; f && i < c.size(); ++i) {
                int t = h[c[i]];
                int d = t / s, k = t % s;
                if (k == 0) {
                    cur += d;
                } else if (k + d >= s - 1) {
                    cur += d + (k > 0);
                } else {
                    f = false;
                }
            }
            if (f && cur < ans) {
                ans = cur;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}