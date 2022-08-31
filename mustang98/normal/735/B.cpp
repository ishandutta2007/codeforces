#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200008;

int m[max_n];

int main()
{
    long long  n, n1, n2;
    //scanf("%d%d%d", &n, &n1, &n2);
    cin >> n >> n1 >> n2;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", m + i);
    }
    sort(m, m + n);

    if (n1 < n2) swap(n1, n2);

    int k = n1 - n2;

    long long s = 0;
    for (int i = 0; i < n1 + n2; ++i)
    {
        s += (ld)m[n - i - 1];
    }

    long long s1 = 0;
    for (int i = 0; i < n2; i++)
    {
        s1 += m[n -i - 1];
    }
    ld ans = (ld)s * n2 + (ld)s1 * (ld)k;//) / (ld)(n1 * n2);
    ans /= (n1 * n2);
    swap(n1, n2);

    ll sum1 = 0;
    ll sum2 = 0;
    k = abs(n1 - n2);

    for (int i = 0; i < n1; i++)
    {
        sum1 += m[n - i - 1];
    }
    for (int i = 0; i < n2; i++)
    {
        sum2 += m[i];
    }

    ld ans2 = (ld)(sum1 + sum2) * n2 - (ld)sum2 * k;
    ans2 /= (n1 * n2);
    cout.precision(100);
    cout << max(ans, ans2);

    return 0;
}