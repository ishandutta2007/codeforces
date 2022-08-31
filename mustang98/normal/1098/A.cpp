#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

vector<int> v[max_n];
int n;
int s[max_n];
int a[max_n];
int p[max_n];

void dfs(int cur, int pr) {
    int mn = inf;
    for (int to : v[cur]) {
        mn = min(mn, s[to]);
        dfs(to, cur);
    }
    if (s[cur] == -1) {
        s[cur] = mn;
        if (mn == inf) {
            s[cur] = s[pr];
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int a;
        cin >> a;
        v[a - 1].PB(i);
        p[i] = a - 1;
    }
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }
    dfs(0, -1);
    ll ans = s[0];
    for (int i = 1; i < n; ++i) {
        if (s[i] < s[p[i]]) {
            cout << -1 << endl;
            exit(0);
        }
        ans += s[i] - s[p[i]];
    }
    cout << ans << endl;
    return 0;
}