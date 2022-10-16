#include <algorithm>
#include <iostream>

using namespace std;

const int N = 200001;
int64_t a[N], p[N], ansm, ansam;
int n;
long double ans = -1;

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
        p[i] = p[i - 1] + a[i];
    for (int m = 0; m < n; ++m)
    {
        int lam = 0, ram = min(m, n - m - 1) + 1;
        while (ram - lam > 1)
        {
            int mam = (lam + ram) / 2;
            int64_t s1 = p[m] - p[m - mam - 1] + p[n - 1] - p[n - 1 - mam];
            int64_t s2 = p[m] - p[m - mam] + p[n - 1] - p[n - mam];
            if (s2 * (2 * mam + 1) < s1 * (2 * mam - 1))
                lam = mam;
            else
                ram = mam;
        }
        if (ans < (p[m] - p[m - lam - 1] + p[n - 1] - p[n - 1 - lam]) / (2. * lam + 1) - a[m])
            ans = (p[m] - p[m - lam - 1] + p[n - 1] - p[n - 1 - lam]) / (2. * lam + 1) - a[m], ansm = m, ansam = 2 * lam + 1;
    }
    for (int m = 1; m < n; ++m)
    {
        int lam = 0, ram = min(m, n - m - 1);
        while (ram - lam > 1)
        {
            int mam = (lam + ram) / 2;
            int64_t s1 = p[m] - p[m - mam - 2] + p[n - 1] - p[n - 1 - mam + 1];
            int64_t s2 = p[m] - p[m - mam - 1] + p[n - 1] - p[n - 1 - mam + 2];
            if (s2 * (2 * mam + 1) < s1 * (2 * mam - 1))
                lam = mam;
            else
                ram = mam;
        }
        if (ans < (p[m] - p[m - lam - 1] + p[n - 1] - p[n - 1 - lam]) / (2. * lam + 2) - (a[m] + a[m - 1]) / 2.)
            ans = (p[m] - p[m - lam - 1] + p[n - 1] - p[n - 1 - lam]) / (2. * lam + 2) - (a[m] + a[m - 1]) / 2., ansm = m, ansam = 2 * lam + 2;
    }
    if (ansam & 1)
    {
        ansam /= 2;
        cout << 2 * ansam + 1 << '\n';
        for (int i = 0; i <= ansam; ++i)
            cout << a[ansm - ansam + i] << ' ';
        for (int i = 0; i < ansam; ++i)
            cout << a[n - ansam + i] << ' ';
    }
    else
    {
        ansam /= 2;
        cout << 2 * ansam << '\n';
        for (int i = 0; i <= ansam; ++i)
            cout << a[ansm - ansam + i] << ' ';
        for (int i = 1; i < ansam; ++i)
            cout << a[n - ansam + i] << ' ';
    }
    return 0;
}