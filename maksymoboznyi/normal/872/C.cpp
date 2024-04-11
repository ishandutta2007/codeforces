#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

bool pr[100000];
vector<int> p;
signed main()
{
    pr[0] = 1;
    pr[1] = 1;
    for (int i = 2; i <= 50000; i++)
        if (!pr[i])
    {
        p.pb(i);
        for (int j = i; j*i <= 50000; j++)
            pr[j*i] = 1;
    }
    int q, n;
    cin >> q;
    for (int j = 0; j < q; j++)
    {
        cin >> n;
        if (n < 8)
            if (n == 4 || n == 6)
                cout << 1<<"\n";
            else
                cout << -1 << "\n";
        else
            if (n % 4 == 0)
                cout << n/4 << "\n";
            else
                if (n % 4 == 1)
                    cout << 1 + (n-9)/4 << "\n";
                else
                    if (n % 4 == 2)
                        cout << 1 + (n-6)/4 << "\n";
                    else
                        if (n % 4 == 3)
                            if (n < 15)
                                cout << -1 << "\n";
                            else
                                cout << 2 + (n-15)/4 << "\n";
    }
    return 0;
}