#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define big 1000000000000000000
#define small -big
using namespace std;

const int N = 1e5;
ll c, v0, v1, a, l;
int main()
{
    cin >> c >> v0 >> v1 >> a >> l;
    long long ans = 0, cur = 0;
    while (cur < c)
    {
        ans++;
        if (ans != 1)
            cur -= l;
        if (ans != 1)
        {
            v0 += a;
            v0 = min(v1, v0);
        };
        cur += v0;
        //cout << cur << endl;
    }
    cout << ans;
    return 0;
}