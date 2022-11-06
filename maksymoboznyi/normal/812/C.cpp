#include <bits/stdc++.h>

using namespace std;

long long n, b[100005], a[100005], s;
bool used[100005];
long long get(long long x)
{
    for (long long i = 1; i <= n; i++)
        a[i] = a[i] + i*x;
    sort(a+1, a+n+1);
    long long cur = 0, ans = 0;
    for (long long i = 1; i <= x; i++)
        cur += a[i];
    for (long long i = 1; i <= n; i++)
        a[i] = b[i];
    return cur;
}
int main()
{
    cin >> n >> s;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }

    for (long long i = 1; i <= n; i++)
        b[i] = a[i];
    long long l = -1, r = n+1;
    while (l < r - 1)
    {
        long long m = (r+l) / 2;
        //cout << m << ' ' << get(m)<<endl;
        if (get(m) <= s)
            l = m;
        else
            r = m;
    }
    cout << l << ' '<< get(l);
    return 0;
}