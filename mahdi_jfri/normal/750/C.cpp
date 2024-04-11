#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const int maxn = 2e5 + 1;
const ll inf = 2e17;
ll r , t , a[maxn] , b[maxn];
int main()
{
    int n;
    cin >> n;
    r = inf;
    for(int i = 0; i < n; i++)
    {
        cin >> b[i] >> a[i];
        if (a[i] == 1 && r + t < 1900)
        {
            cout << "Impossible";
            return 0;
        }
        if (a[i] == 2 && r + t > 1899)
            r = 1899 - t;
        t += b[i];
    }
    for(int i = 0; i < n; i++)
    {
        if (a[i] == 1 && r < 1900)
        {
            cout << "Impossible";
            return 0;
        }
        if (a[i] == 2 && r > 1899)
        {
            cout << "Impossible";
            return 0;
        }
        r += b[i];
    }
    if (r > inf / 2)
        cout << "Infinity";
    else
        cout << r;
}