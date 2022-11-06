#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define x first
#define y second

using namespace std;

const int N = 5e5+5;
const long long inf = 2e18;

long long n, a[N];

signed main()
{
    long long l = 0, r = 2e18;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    if (a[0] == 0)
    {
        cout << 1;
        return 0;
    }
    int pos = 0, kpos = 2e18;
    for (int i = 0; i < n; i++)
    {
        int q = 0;
        int k = (a[i]-i-1)/n+1;
        if (a[i] - i - 1 < 0)
            k = 0;
        //cout << i << ' ' << k << ' ' << k*n+i << endl;
        if (k *n+i< kpos)
            kpos = k*n+i, pos = i;
    }
    cout << pos+1;
    return 0;
}