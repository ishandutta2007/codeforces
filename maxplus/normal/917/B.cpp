#include <bits/stdc++.h>

using namespace std;
using pint = pair<int, int>;

constexpr int N = 1e2;

vector<pint> nei[N];

void pack(int a, int b, int c, int r, int &s) {
    s = (a * N + b) * N + c * 2 + r;
}

void unpack(int &a, int &b, int &c, int &r, int s) {
    r = s % 2;
    c = s % N / 2;
    b = s / N % N;
    a = s / N / N;
}

int8_t W[N * N * N];

int w(int a, int b, int c, int r) {
    int s;
    pack(a, b, c, r, s);
    if (W[s] != -1)
        return W[s];
    W[s] = 0;
    int &cur = r? b: a;
    for (auto i: nei[cur]) if (i.second >= c) {
        swap(cur, i.first);
        W[s] |= !w(a, b, i.second, !r);
        swap(cur, i.first);
    }
    return W[s];
}

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    memset(W, 255, sizeof W);
    int n, m, a, b;
    char c;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> a >> b >> c, nei[--a].push_back({--b, c - 'a'});
    for (int a = 0; a < n; ++a, cout << '\n')
    for (int b = 0; b < n; ++b)
        cout.put('B' - w(a, b, 0, 0));
    return 0;
}