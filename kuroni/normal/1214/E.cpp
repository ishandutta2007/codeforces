#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 100005;

int n;
pair<int, int> a[N];
vector<int> ve;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a + 1, a + n + 1, greater<pair<int, int>>());
    for (int i = 1; i <= n; i++)
        ve.push_back(2 * a[i].se - 1);
    for (int i = 1; i <= n; i++)
    {
        int nxt = a[i].fi + i - 2;
        if (nxt == ve.size() - 1)
            ve.push_back(2 * a[i].se);
        else
            cout << ve[nxt] << " " << 2 * a[i].se << '\n';
    }
    for (int i = 1; i < ve.size(); i++)
        cout << ve[i - 1] << " " << ve[i] << '\n';
}