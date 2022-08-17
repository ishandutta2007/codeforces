#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111;

bool yex[max_n];
vector<int> yexv;
map<int, int> hrev;

int main()
{
    int n;
    int f[max_n];
    int h[max_n];
    int g[max_n];
    scanf("%d", &n);
    for (int x = 1; x <= n; ++x)
    {
        scanf("%d", &f[x]);
        if (f[x] == x)
        {
            yex[x] = true;
        }
    }
    int m = 0;
    for (int x = 1; x <= n; ++x)
    {
        int y = f[x];
        if (y == x)
        {
            yexv.pb(x);
        }
        if (yex[y] == false)
        {
            cout << -1;
            return 0;
        }
    }
    m = yexv.size();
    printf("%d\n", m);
    for (int x = 1; x <= m; ++x)
    {
        h[x] = yexv[x - 1];
        hrev[yexv[x - 1]] = x;
    }
    for (int x = 1; x <= n; ++x)
    {
        g[x] = hrev[f[x]];
        printf("%d ", g[x]);
    }
    printf("\n");
    for (int x = 1; x <= m; ++x)
    {
        printf("%d ", h[x]);
    }
    return 0;
}