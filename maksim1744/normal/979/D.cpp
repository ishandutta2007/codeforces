/*
    18.03.2019 14:23:42
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const int mxn = 1e5 + 10;

struct Node {
    int to[2];
    int cnt = 0;
    int mn = 100000 + 10;

    Node() {
        to[0] = to[1] = -1;
    }

    bool end() {
        return to[0] == -1 && to[1] == -1;
    }
};

vector< Node > nodes(mxn);
int inodes = mxn - 1;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector< bool > has(mxn, false);
    int q;
    cin >> q;
    auto add = [](int node, int u) {
        // vector< int > b;
        int base = 1 << 17;
        // int u = u;
        // while (u != 0) {
        //     b.push_back(u & 1);
        //     u >>= 1;
        // }
        // b.resize(18, 0);
        // reverse(b.begin(), b.end()());
        for (int i = 0; i < 18; ++i) {
            int bi = ((base & u) != 0);
            ++nodes[node].cnt;
            nodes[node].mn = min(nodes[node].mn, u);
            if (nodes[node].to[bi] == -1) {
                nodes[node].to[bi] = ++inodes;
                nodes.emplace_back();
            }
            node = nodes[node].to[bi];
            base >>= 1;
        }
        ++nodes[node].cnt;
        nodes[node].mn = min(nodes[node].mn, u);
    };
    auto findX = [](int node, int x, int s) {
        if (nodes[node].cnt == 0 || nodes[node].mn > s - x) return -1;
        int base = 1 << 17;
        int ans = -1;
        int val = 0;
        int xnow = 0;
        int xans = -1;
        // show(nodes[node].mn, b);
        for (int i = 0; i < 18; ++i) {
            int bi = ((base & x) != 0);
            // show(i, xnow, xans, nodes[node].end());
            if (nodes[node].to[bi^1] != -1 &&
                nodes[nodes[node].to[bi^1]].cnt > 0 &&
                nodes[nodes[node].to[bi^1]].mn <= s - x) {
                val += (1 << (17 - i));
                xnow += (bi^1) << (17 - i);
                node = nodes[node].to[bi^1];
                if (nodes[node].end() && val > ans) {
                    ans = val;
                    xans = xnow;
                }
            } else if (nodes[node].to[bi] != -1 &&
                       nodes[nodes[node].to[bi]].mn <= s - x &&
                       nodes[nodes[node].to[bi]].cnt > 0) {
                xnow += bi << (17 - i);
                node = nodes[node].to[bi];
                if (nodes[node].end() && val > ans) {
                    ans = val;
                    xans = xnow;
                }
            } else {
                break;
            }
            base >>= 1;
        }
        return xans;
    };
    for (int ii = 0; ii < q; ++ii) {
        int t;
        cin >> t;
        if (t == 1) {
            int u;
            cin >> u;
            if (!has[u]) {
                has[u] = true;
                int k;
                for (k = 1; k * k < u; ++k) {
                    if (u % k == 0) {
                        add(k, u);
                        add(u / k, u);
                    }
                }
                show(u, k);
                if (k * k == u)
                    add(k, u);
            }
        } else {
            int x, k, s;
            cin >> x >> k >> s;
            if (x % k != 0 || x > s) {
                cout << -1 << '\n';
            } else {
                cout << findX(k, x, s) << '\n';
            }
        }
    }
    return 0;
}