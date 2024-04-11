#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define big 1000000000000000000
#define small -big
using namespace std;

double n, x, ans = 1000000000;
int a, b, c;

int main()
{
    cin >> n >> x;
    double u1 = 180/n;

    for (int i = 1; i <= n-2; i++)
    {
        double u2 = u1*i;
        if (abs(u2-x) < ans)
        {
            b = 1;
            a = n;
            c = n - i;
            ans = abs(u2-x);
        }
    }
    cout << a << ' ' << b << ' ' << c;
    return 0;
}