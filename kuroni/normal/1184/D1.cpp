#include <bits/stdc++.h>
using namespace std;

int n, k, q, t, u;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> q >> q;
    while (q--)
    {
        cin >> t >> u;
        if (t == 1)
        {
            n++;
            k += (u <= k);
        }
        else
        {
            if (u < k)
            {
                n -= u;
                k -= u;
            }
            else
                n = u;
        }
        cout << n << " " << k << '\n';
    }
}