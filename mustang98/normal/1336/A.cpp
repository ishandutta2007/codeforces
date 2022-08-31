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

vector<int> v[max_n];
int p[max_n];
int sz[max_n];

void dfs(int cur, int d, int pr) {
    sz[cur] = 1;
    for (int to : v[cur]) {
        if (to == pr) {
            continue;
        }
        dfs(to, d + 1, cur);
        sz[cur] += sz[to];
    }
    p[cur] = -sz[cur] + 1 + d;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i + 1 < n; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        v[a].PB(b);
        v[b].PB(a);
    }
    dfs(0, 0, -1);

    sort(p, p + n);
    reverse(p, p + n);
    ll ans = 0;
    for (int i = 0; i < k; ++i) {
        ans += p[i];
    }
    cout << ans << endl;

    return 0;
}