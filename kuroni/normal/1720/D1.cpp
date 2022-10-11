#include <bits/stdc++.h>
using namespace std;

const int LG = 30;

struct trie {
    int n;
    vector<array<int, 2>> ch, ans;

    trie() {
        n = 1;
        ch = {{-1, -1}};
        ans = {{-1, -1}};
    }

    int traverse(int a, int i) {
        int val = a ^ i;
        int ret = 0;
        for (int b = LG, cur = 0; b >= 0 && cur != -1; b--) {
            int bv = val >> b & 1, bi = i >> b & 1;
            int nxt = ch[cur][bv], oth = ch[cur][bv ^ 1];
            if (oth != -1) {
                ret = max(ret, ans[oth][bv ^ 1 ^ bi]);
            }
            cur = nxt;
        }
        return ret;
    }

    void add(int a, int i, int ret) {
        int val = a ^ i;
        for (int b = LG, cur = 0; b >= 0; b--) {
            int bv = val >> b & 1, bi = i >> b & 1;
            int nxt = ch[cur][bv];
            if (nxt == -1) {
                nxt = ch[cur][bv] = n++;
                ans.push_back({-1, -1});
                ch.push_back({-1, -1});
            }
            ans[nxt][bi] = max(ans[nxt][bi], ret);
            cur = nxt;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n), dp(n);
        trie cur;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            dp[i] = cur.traverse(a[i], i) + 1;
            cur.add(a[i], i, dp[i]);
        }
        cout << *max_element(dp.begin(), dp.end()) << '\n';
    }
}