#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, m;
int a[Maxn];
ll sum;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }
    sort(a, a + n);
    ll rem = 0;
    int nd = 1;
    for (int i = 0; i < n; i++)
        if (a[i] >= nd) { rem++; nd++; }
        else rem++;
    if (nd <= a[n - 1]) rem += a[n - 1] - nd + 1;
    cout << sum - rem << endl;
    return 0;
}