#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

const int N = 1e5+5;
const long long inf = 2e18;
const long long M = 1e9+7;
int x, k;

int st(int a, int b)
{
    int res = 1;
    while ( b > 0)
        if (b % 2 == 0)
            b /= 2, a = (a*a)%M;
        else
            b--, res = (res*a)%M;
        return res;
}

signed main()
{
    cin >> x >> k;
    if (x == 0)
    {
        cout << 0;
        return 0;
    }
    x %= M;
    int y = st(2, k);
    int a = (((x*y)%M)*2)%M;
    int b = (y-1+M)%M;
    cout << (a+M+M+M-b)%M;
    return 0;
}