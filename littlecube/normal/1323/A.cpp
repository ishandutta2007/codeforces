#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int odd1 = 0,  odd = 0, tmp, success = 0;
        int i = 1;
        for (; i <= n; i++)
        {
            cin >> tmp;
            if (tmp % 2 == 0){
                success = 1;
                cout << 1 << '\n'<< i << '\n';
                break;
            }
            else if (odd == 0)
            {
                odd = tmp;
                odd1 = i;
            }
            else{
                cout << 2 << '\n' << odd1 << " " << i << '\n';
                success = 1;
                break;
            }
        }
        for (; i < n; i++)
        {
            cin >> tmp;
        }
        if(!success)
            cout << "-1\n";
    }
}