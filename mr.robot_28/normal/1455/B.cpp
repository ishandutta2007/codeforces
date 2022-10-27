
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int x;
        cin >> x;
        int sum = 0;
        int i = 1;
        while(sum + i <= x)
        {
            sum += i;
            i++;
        }
        if(sum != x)
        {
            if(sum + i == x + 1)
            {
                cout << i + 1 << "\n";
            }
            else
            {
            cout << i << "\n";
            }
        }
        else
        {
            cout << i - 1 << "\n";
        }
    }
    return 0;
}