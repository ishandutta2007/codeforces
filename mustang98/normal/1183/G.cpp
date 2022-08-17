#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

int c0[max_n];
int c1[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int q;
    cin >> q;
    while(q--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            c0[i] = c1[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            --a;
            if (b == 0) {
                c0[a]++;
            } else {
                c1[a]++;
            }
        }
        vector<int> h;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i) {
            v.emplace_back(c0[i] + c1[i], c1[i]);
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        int cur_val = 1e9;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            cur_val = min(cur_val, v[i].F);
            h.PB(cur_val);
            ans += cur_val;
            --cur_val;
            if (cur_val <= 0) break;
        }
        int ans1 = 0;
        reverse(v.begin(), v.end());
        multiset<int> ms;
        for (int i = 0; i < h.size(); ++i) {
            while(!v.empty() && v.back().F >= h[i]) {
                ms.insert(v.back().S);
                v.pop_back();
            }
            if (ms.empty()) {
                exit(228);
            }
            auto it = ms.end();
            --it;
            ans1 += min(h[i], *it);
            ms.erase(it);
        }
        printf("%d %d\n", ans, ans1);

    }

    return 0;
}