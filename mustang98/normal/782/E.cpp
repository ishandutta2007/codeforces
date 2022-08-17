#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111;

vector<int> v[max_n];
vector<int> ans;
bool vis[max_n];

void DFS(int cur)
{
    vis[cur] = true;
    ans.pb(cur);
    for (int to : v[cur]) {
        if (!vis[to]) {
            DFS(to);
            ans.pb(cur);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, a, b, l, k;
    cin >> n >> m >> k;
    for (int i = 0; i <m; ++i) {
        scanf("%d%d", &a, &b);
        --a, --b;
        v[a].pb(b);
        v[b].pb(a);
    }
    DFS(0);
    l = ans.size() / k;
    int cur = 0;
    for (int i = 0; i < k; ++i) {
        int d = min(l, (int)ans.size() - cur);
        if (i < ans.size() % k) {
            ++d;
        }
        printf("%d ", d);
        for (int j = 0; j < d; ++j) {
            //cout << ans[cur] + 1 << ' ';
            printf("%d ", ans[cur] + 1);
            ++cur;
        }
        printf("\n");
        //cout << endl;
    }

    return 0;
}