#include <iostream>
#include <algorithm>
using namespace std;

int i, n, k, x;
long long ans = 0;

struct item
{
    int ini, c;
}   a[200005];

bool compare(item a, item b)
{
    return a.c < b.c;
}

int main()
{
	cin >> n >> k;
    for (i = 1; i <= n; i++) cin >> a[i].ini;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        a[i].c = a[i].ini - x;
    }
    sort(a + 1, a + 1 + n, compare);
    i = 1;
    while ((a[i].c <= 0 || i <= k) && i <= n)
    {
        ans += a[i].ini;
        i++;
    }
    for (k = i; k <= n; k++) ans += a[k].ini - a[k].c;
    cout << ans;
	return 0;
}