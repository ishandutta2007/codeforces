#include <bits/stdc++.h>

using namespace std;

const int N = 1011;
const int INF = N * N;
const int M = (int) 2e5 + 10;

int d[N][N];
vector<int> r[M];
vector<int> id[M];
vector<int> from[M];
vector<int> to[M];
bool ans[M];
int a[M];
int b[M];
int n, m, q;

void addEdge(int s, int t, int len) {
    d[s][t] = d[t][s] = len;
    for (int v = 0; v < n; v++) {
        if (v == s || v == t)
            continue;
        int mn = d[s][v] < d[t][v] ? d[s][v] : d[t][v];
        d[s][v] = d[t][v] = mn;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j)
                d[i][j] = INF;
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    for (int i = 0; i < q; i++) {
        int low, high, s, t;
        cin >> low >> high >> s >> t;
        low--;
        high--;
        s--;
        t--;
        r[low].push_back(high);
        id[low].push_back(i);
        from[low].push_back(s);
        to[low].push_back(t);
    }
    for (int i = m - 1; i >= 0; i--) {
        addEdge(a[i], b[i], i);
        for (int j = 0; j < r[i].size(); j++)
            ans[id[i][j]] = (d[from[i][j]][to[i][j]] <= r[i][j]);
    }     
    for (int i = 0; i < q; i++)
        cout << (ans[i] ? "Yes" : "No") << "\n";   
    return 0;
}