#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 26, inf = 1000111222;

string a, b;
vector<int> v[26];

bool vis[max_n];
vector<pair<int, int> > ans;


void dfs(int cur, int pr) {
    vis[cur] = 1;
    if (pr != -1) {
        ans.PB(MP(cur, pr));
    }

    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (!vis[to]) {
            dfs(to, cur);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    cin >> a;
    cin >> b;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            int v1 = int(a[i] - 'a');
            int v2 = int(b[i] - 'a');
            v[v1].PB(v2);
            v[v2].PB(v1);
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (!vis[i]) {
            dfs(i, -1);
        }
    }

    cout << ans.size() << endl;
    for (pair<int, int> a : ans) {
        cout << char('a' + a.F) << ' ' << char('a' + a.S) << endl;
    }

    return 0;
}