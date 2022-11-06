#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 1e5 + 5;
const long long inf = 2e18;


signed main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    int nr;
    int n, m, k;
    cin >> n >> m >> k;
    nr = n;
    int mr = m;
    int x = __gcd(n, k);
    n /= x;
    k /= x;
    x = __gcd(k, m);
    m /= x;
    k /= x;
    if (k > 2)
    {
        cout << "NO";
        return 0;
    }
    if (k == 2)
    {
        cout << "YES\n";
        cout << "0 0\n0 " << m << "\n" << n << " 0";
    }else
    {
        int nn = 2*n;
        if (m * 2 <= mr)
            m *= 2, nn /= 2;
        if (nn > nr)
        {
            cout << "NO";
            return 0;
        }
        cout << "YES\n";
        cout << "0 0\n0 " << m << "\n" << nn << " 0";
    }
    return 0;
}