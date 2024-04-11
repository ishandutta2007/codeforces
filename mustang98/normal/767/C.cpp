#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111;
int n;

vector<int> v[max_n];
int w[max_n];
int d[max_n];
int subsum[max_n] = {0};
int needs = 0, root, p;

void find_subsum(int cur, int p, int dep)
{
    d[cur] = dep;
    if (v[cur].size() == 1 && p != -1)
    {
        subsum[cur] = w[cur];
        return;
    }
    subsum[cur] = w[cur];
    for (int to : v[cur])
    {
        if (to == p) continue;
        find_subsum(to, cur, dep + 1);
        subsum[cur] += subsum[to];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d%d", &p, &w[i]);
        p--;
        if (p == -1) {
            root = i;
        }
        else {
            v[i].pb(p);
            v[p].pb(i);
        }
        needs += w[i];
    }

    if (needs % 3 != 0)
    {
        cout << -1;
        return 0;
    }
    needs /= 3;
    find_subsum(root, -1, 0);

    int ans1 = -1, ans2 = -1, maxd = -3;

    for (int i = 0; i < n; ++i)
    {
        if (i == root) continue;
        if (subsum[i] == needs && d[i] > maxd) {
            maxd = d[i];
            ans1 = i;
        }
    }

    if (ans1 == -1) {
        cout << -1;
        return 0;
    }

    int pr;
    for (int to : v[ans1])
    {
        if (d[to] < d[ans1]) {
            pr = to;
            break;
        }
    }

    for (int i = 0; i < v[pr].size(); ++i) {
        if (v[pr][i] == ans1) {
            v[pr].erase(v[pr].begin() + i);
            break;
        }
    }

    find_subsum(root, -1, 0);

    maxd = -3;

    for (int i = 0; i < n; ++i)
    {
        if (i == root || i == ans1) continue;
        if (subsum[i] == needs && d[i] > maxd) {
            maxd = d[i];
            ans2 = i;
        }
    }

    if (ans2 == -1) {
        cout << -1;
        return 0;
    }

    cout << ans1 + 1 << ' ' << ans2 + 1;

    return 0;
}