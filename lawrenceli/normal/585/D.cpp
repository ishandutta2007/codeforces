#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int maxn = 30;

int n, l[maxn], m[maxn], w[maxn];
map<pii, int> mp;

bool used;
int num[maxn];

int ans = -1e9;
int a1, b1, c1, a2, b2, c2;

void dfs(bool flag, int a=0, int b=0, int c=0, int k=0) {
    if (k == n/2) {
        if (flag) {
            if (a == a1 && b == b1 && c == c1 && !used) {
                used = 1;
                for (int i = 0; i < n/2; i++) {
                    if (num[i] == 0) cout << "MW\n";
                    else if (num[i] == 1) cout << "LW\n";
                    else cout << "LM\n";
                }
            }
            return;
        }

        pii p = pii(b - a, c - a);
        if (mp.count(p)) mp[p] = max(mp[p], a);
        else mp[p] = a;
    } else {
        num[k] = 2, dfs(flag, a + l[k], b + m[k], c, k+1);
        num[k] = 1, dfs(flag, a + l[k], b, c + w[k], k+1);
        num[k] = 0, dfs(flag, a, b + m[k], c + w[k], k+1);
    }
}

void dfs2(bool flag, int a=0, int b=0, int c=0, int k=n/2) {
    if (k == n) {
        if (flag) {
            if (a == a2 && b == b2 && c == c2 && !used) {
                used = 1;
                for (int i = n/2; i < n; i++) {
                    if (num[i] == 0) cout << "MW\n";
                    else if (num[i] == 1) cout << "LW\n";
                    else cout << "LM\n";
                }
            }
            return;
        }

        pii p = pii(a - b, a - c);
        if (mp.count(p) && a + mp[p] > ans) {
            ans = a + mp[p];
            a1 = mp[p], b1 = a1 + p.fi, c1 = a1 + p.se;
            a2 = a, b2 = b, c2 = c;
        }
    } else {
        num[k] = 2, dfs2(flag, a + l[k], b + m[k], c, k+1);
        num[k] = 1, dfs2(flag, a + l[k], b, c + w[k], k+1);
        num[k] = 0, dfs2(flag, a, b + m[k], c + w[k], k+1);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> l[i] >> m[i] >> w[i];

    dfs(0);
    dfs2(0);

    if (ans == -1e9) cout << "Impossible\n";
    else {
        dfs(1);
        used = 0;
        dfs2(1);
    }
}