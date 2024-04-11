#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 150111, inf = 1000111222;

vector<pair<int, int> > v[max_n];
bool visv[max_n];
bool vise[max_n];

ll ecnt = 0, vcnt = 0;

void dfs(int cur) {
    vcnt++;
    visv[cur] = 1;
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i].F, e = v[cur][i].S;
        if (!vise[e]) {
            vise[e] = 1;
            ecnt++;
        }
        if (!visv[to]) {
            dfs(to);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int a, b, n, m;
    cin >> n >> m;
    int edge = 0;
    for (int i = 0 ;i  < m; ++i) {
        scanf("%d%d", &a, &b);
        --a, --b;
        v[a].pb(mp(b, edge));
        v[b].pb(mp(a, edge));
        ++edge;
    }
    for (int i = 0; i < n; ++i) {
        if (!visv[i]) {
            vcnt = ecnt = 0;
            dfs(i);
            if ((vcnt * (vcnt - 1) / 2) != ecnt) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}