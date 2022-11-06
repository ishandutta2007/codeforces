#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ll long long
using namespace std;

long long a[100005], n;
long long gcc(long long a, long long b)
{
    while (a != 0 && b != 0)
        if (a > b)
            a %= b;
        else
            b %= a;
    return a+b;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    long long gc = abs(a[0]);
    for (int i = 1; i < n; i++)
        gc = gcc(abs(a[i]), gc);
    if (gc != 1)
    {
        cout << "YES" << endl << 0;
        return 0;
    }
    long long ans = 0, x;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] % 2 == 1 && a[i+1]%2 == 1)
        {
            x = a[i];
            a[i] = a[i]-a[i+1];
            a[i+1] = x+a[i+1];
            ans++;
        }else
        if (a[i] % 2 == 1 && a[i+1] % 2 == 0)
        {
            ans += 2;
            x = a[i];
            a[i] = -2*a[i+1];
            a[i+1] = 2*x;
        }
    }
    if (a[n-1] % 2 == 1)
    {
        ans += 2;
        a[n-2] = -2*a[n-1];
        a[n-1] = 2*a[n-2];
    }
    cout << "YES" << endl << ans;
    return 0;
}