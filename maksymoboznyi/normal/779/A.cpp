#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define big 9999999999
#define small -big
using namespace std;

int n, a[1000], b[1000];
struct cell
{
    int a, b;
};
cell g[1000];
int ans = 0;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        g[a[i]].a++;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        g[b[i]].b++;
    }
    ans = 0;
    for (int i = 1; i < 6; i++)
    {
        if ((g[i].a + g[i].b)%2 == 1)
        {
            cout << -1;
            return 0;
        }
        ans += abs(g[i].a-(g[i].b+g[i].a)/2);
        //cout << g[i].a << ' ' << g[i].b << ' ' << ans << endl;
    }
    cout << ans / 2;
    return 0;
}