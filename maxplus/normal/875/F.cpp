#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()

using namespace std;
using pint = pair<int, int>;
using pintp = pair<int, pint>;

constexpr int N = 2e5;

int p[N + 1], done[N + 1];

int getp(int i) {
    return p[i]? p[i] = getp(p[i]): i;
}

int uni(int i, int j) {
    return p[getp(i)] = getp(j);
}

pintp a[N];

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    int n, m, res = 0;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> a[i].second.first >> a[i].second.second >> a[i].first;
    sort(a, a + m);
    reverse(a, a + m);
    for (int i = 0; i < m; ++i)
        if (done[getp(a[i].second.first)] && done[getp(a[i].second.second)])
            continue;
        else if (!done[getp(a[i].second.first)] && !done[getp(a[i].second.second)] && getp(a[i].second.first) != getp(a[i].second.second))
            res += a[i].first, uni(a[i].second.first, a[i].second.second);
        else
            res += a[i].first, done[getp(a[i].second.first)] = done[getp(a[i].second.second)] = 1;
    cout << res;
    return 0;
}