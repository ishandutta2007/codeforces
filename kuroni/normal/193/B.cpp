#include <bits/stdc++.h>
using namespace std;

const int N = 35;
const long long INF = 1E18 + 7;

int n, u, r;
long long sum = 0, ans = -INF;
vector<long long> a, b, k, p;
vector<int> con[N];

void read(vector<long long> &ve) {
    ve = vector<long long>(n);
    for (int i = 0; i < n; i++) {
        cin >> ve[i];
    }
}

void DFS(int cur, int lst, vector<long long> &ve) {
    vector<long long> nv(n);
    int dis = cur - lst - 1;
    for (int i = 0; i < n; i++) {
        nv[i] = (cur == 0 ? ve[i] : ((ve[con[dis][i]] + dis * r) ^ b[i]));
    }
    for (int i = (u - cur) % 2; i <= u - cur; i += 2) {
        long long cur = 0;
        for (int j = 0; j < n; j++) {
            cur += k[j] * (nv[con[i][j]] + i * r);
        }
        ans = max(ans, cur);
    }
    for (int i = (cur > 0 ? cur + 2 : 1); i <= u; i++) {
        DFS(i, cur, nv);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> u >> r;
    read(a);
    read(b);
    read(k);
    read(p);
    for (int i = 0; i < n; i++) {
        sum += k[i];
        p[i]--;
        con[0].push_back(i);
    }
    for (int i = 1; i <= u; i++) {
        con[i] = vector<int>(n);
        for (int j = 0; j < n; j++) {
            con[i][j] = con[i - 1][p[j]];
        }
    }
    DFS(0, 0, a);
    cout << ans;
}