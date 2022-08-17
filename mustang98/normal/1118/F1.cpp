#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 300111, inf = 1000111222;

int c1[max_n];
int c2[max_n];
int a1 = 0, a2 = 0;
int col[max_n];
vector<int> v[max_n];
int n;

int ans = 0;

void dfs(int cur, int pr) {
    if (col[cur] == 1) {
        c1[cur] = 1;
        a1++;
    }
    if (col[cur] == 2) {
        c2[cur] = 1;
        a2++;
    }
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (to == pr) continue;
        dfs(to, cur);
        c1[cur] += c1[to];
        c2[cur] += c2[to];
    }
}

void dfs2(int cur, int pr) {
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (to == pr) continue;
        dfs2(to, cur);
        int c1d = c1[to];
        int c2d = c2[to];
        int c1u = a1 - c1d;
        int c2u = a2 - c2d;
        if (c1d && c2d) continue;
        if (c1u && c2u) continue;
        ++ans;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", col + i);
    }
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        v[a].PB(b);
        v[b].PB(a);
    }
    dfs(0, -1);
    dfs2(0, -1);
    cout << ans << endl;
    return 0;
}