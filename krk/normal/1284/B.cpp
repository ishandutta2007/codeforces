#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Inf = 1000000000;

int n;
vector <int> V[Maxn];
ll res;
vector <int> mins, maxs;

int main()
{
    scanf("%d", &n);
    int lft = n;
    for (int i = 0; i < n; i++) {
        int cnt; scanf("%d", &cnt);
        V[i].resize(cnt);
        bool has = false;
        int mn = Inf, mx = -Inf;
        for (int j = 0; j < cnt; j++) {
            scanf("%d", &V[i][j]);
            if (mn < V[i][j]) has = true;
            mn = min(mn, V[i][j]);
            mx = max(mx, V[i][j]);
        }
        if (has) { res += 2 * lft - 1; lft--; }
        else { mins.push_back(mn); maxs.push_back(mx); }
    }
    sort(mins.begin(), mins.end());
    for (int i = 0; i < maxs.size(); i++)
        res += lower_bound(mins.begin(), mins.end(), maxs[i]) - mins.begin();
    cout << res << endl;
    return 0;
}