#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
ll res;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (a[i] > a[mx]) mx = i;
    }
    int g = 0;
    for (int i = 0; i < n; i++)
        g = gcd(g, a[mx] - a[i]);
    for (int i = 0; i < n; i++)
        res += (a[mx] - a[i]) / g;
    cout << res << " " << g << endl;
    return 0;
}