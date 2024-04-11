#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 100005;

vector<pair<int, LL>> e[N];

bool visited[N];
LL h[N];
vector<LL> cycles;
vector<LL> hs;

int dfs(int x) {
    visited[x] = true;
    hs.push_back(h[x]);
    for (const auto& p : e[x]) {
        if (visited[p.first]) {
            LL ch = h[p.first] ^ h[x] ^ p.second;
            if (ch != 0) {
                cycles.push_back(ch);
            }
        } else {
            h[p.first] = h[x] ^ p.second;
            dfs(p.first);
        }
    }
}

const int BITS = 61;

void gauss() {
    int last = 0;
    for (int i = 0; i < BITS; ++i) {
        for (int j = last; j < cycles.size(); ++j) {
            if ((cycles[j] >> i) & 1) {
                for (int k = 0; k < cycles.size(); ++k) {
                    if ((k != j) && ((cycles[k] >> i) & 1)) {
                        cycles[k] ^= cycles[j];
                    }
                }
                swap(cycles[last], cycles[j]);
                ++last;
                break;
            }
        }
    }
    cycles.resize(last);
}

const int MD = (int)1e9 + 7;

LL count_one(int b) {
    int a0 = 0;
    int a1 = 0;
    for (const auto& x : hs) {
        if ((x >> b) & 1) {
            ++a1;
        } else {
            ++a0;
        }
    }
    int c0 = 0;
    int c1 = 0;
    for (const auto& x : cycles) {
        if ((x >> b) & 1) {
            ++c1;
        } else {
            ++c0;
        }
    }
    LL x0, x1;
    if (c1 == 0) {
        x0 = (1LL << (c0 + c1));
        x1 = 0;
    } else {
        x0 = (1LL << (c0 + c1 - 1));
        x1 = (1LL << (c0 + c1 - 1));
    }
    LL y0 = (a0 * (LL)(a0 - 1)) / 2 + (a1 * (LL)(a1 - 1)) / 2;
    LL y1 = a0 * (LL)a1;
    return ((y1 % MD) * (x0 % MD) + (y0 % MD) * (x1 % MD)) % MD;
}

LL sum_all() {
    LL result = 0;
    for (int i = 0; i < BITS; ++i) {
        result += (count_one(i) * ((1LL << i) % MD)) % MD;
        result %= MD;
    }
    return result;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        LL t;
        cin >> u >> v >> t;
        e[u].push_back(make_pair(v, t));
        e[v].push_back(make_pair(u, t));
    }
    LL result = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cycles.clear();
            hs.clear();
            dfs(i);
            gauss();
            result += sum_all();
            result %= MD;
        }
    }
    cout << result << endl;
}