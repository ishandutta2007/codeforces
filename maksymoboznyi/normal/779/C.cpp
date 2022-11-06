#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define big 9999999999
#define small -big
using namespace std;
struct cell
{
    ll a, b;
};
cell g[200005];
ll n, k;
vector <cell> ch, nch;

bool cmp(cell a, cell b)
{
     return (a.a - a.b < b.a - b.b);

}
bool used[200005];
int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i].a;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> g[i].b;
    }
    ll ans = 0;
    sort(g, g + n, cmp);
    int p = 0;
    for (int i = 0; i < n; i++)
        if (g[i].a <= g[i].b)
        {
            p++;
            ans += g[i].a;
            used[i] = true;
        }
    for (int i = 0; i < n; i++)
        if (!used[i] & p < k)
        {
            ans += g[i].a;
            used[i] = true;
            p++;
        }

    for (int i = k; i < n; i++)
        if (!used[i])
            ans += min(g[i].a, g[i].b);
    cout << ans;
    return 0;
}