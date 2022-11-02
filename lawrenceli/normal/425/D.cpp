#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#include <ios>

using namespace std;

typedef pair<int, int> pii;

const int maxn = 100100;
const int DIV = 500;

int n;
vector<int> v[maxn], w[maxn];
vector<pii> q[maxn];
int last[maxn];

int ans;

void check(int y, int a, int b, bool k) {
    if (y < 0 || y >= maxn || v[y].empty()) return;
    if (v[y].size() <= DIV && !k) return;
    q[y].push_back(pii(a, b));
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[y].push_back(x);
    }

    for (int i = 0; i < maxn; i++)
        sort(v[i].begin(), v[i].end());

    for (int i = 0; i < maxn; i++)
        if (v[i].size() <= DIV)
            for (int j = 0; j < v[i].size(); j++)
                for (int k = j + 1; k < v[i].size(); k++) {
                    int d = v[i][k] - v[i][j];
                    check(i - d, v[i][j], v[i][k], 0);
                    check(i + d, v[i][j], v[i][k], 1);
                }

    memset(last, -1, sizeof(last));
    for (int i = 0; i < maxn; i++) {
        for (int j : v[i])
            last[j] = i;

        for (pii p : q[i])
            if (last[p.first] == i && last[p.second] == i)
                ans++;
    }

    for (int i = 0; i < maxn; i++)
        if (v[i].size() > DIV)
            for (int j = 0; j < v[i].size(); j++)
                w[v[i][j]].push_back(i);

    for (int i = 0; i < maxn; i++) {
        sort(w[i].begin(), w[i].end());
        v[i] = w[i];
    }

    for (int i = 0; i < maxn; i++)
        q[i].clear();

    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < v[i].size(); j++)
            for (int k = j + 1; k < v[i].size(); k++) {
                int d = v[i][k] - v[i][j];
                check(i + d, v[i][j], v[i][k], 1);
            }

    memset(last, -1, sizeof(last));
    for (int i = 0; i < maxn; i++) {
        for (int j : v[i])
            last[j] = i;

        for (pii p : q[i])
            if (last[p.first] == i && last[p.second] == i)
                ans++;
    }

    cout << ans << '\n';
}