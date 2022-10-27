#include<bits/stdc++.h>
using namespace std;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    while(n--)
    {
        long long p, q, b;
        cin >> p >> q >> b;
        if(p == 0)
        {
            cout << "Finite\n";
            continue;
        }
        long long u = __gcd(p, q);
        p /= u;
        q /= u;
        long long t = b;
        while((t = __gcd(q, t)) != 1)
        {
            q /= t;
        }
        //cout << u << "\n";
        if(q != 1)
        {
            cout << "Infinite\n";
        }
        else
        {
            cout << "Finite\n";
        }
    }
    return 0;
}