#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int n, s;
int a[Maxn];
long long res;

int main()
{
    scanf("%d %d", &n, &s);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    int mid = n / 2;
    res += abs(a[mid] - s);
    for (int i = mid + 1; i < n; i++)
        if (a[i] < s) res += s - a[i];
    for (int i = 0; i < mid; i++)
        if (a[i] > s) res += a[i] - s;
    cout << res << endl;
    return 0;
}