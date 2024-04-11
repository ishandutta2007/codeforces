#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

using namespace __gnu_pbds;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        for(int i = 0; i < k * 2 - n - 1; i++)
        {
            cout << i + 1 << " ";
        }
        for(int i = k; i > k * 2 - n - 1; i--)
        {
            cout << i  << " ";
        }
        cout << "\n";
    }
    return 0;
}