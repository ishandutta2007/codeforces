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
        
        while (1)
        {
            ll j = n;
            bool s = true;
            while (j != 0)
            {
                if (j % 10 == 0)
                {
                    j /= 10;
                    continue;
                }
                if (n % (j % 10) != 0)
                {
                    s = 0;
                }
                j /= 10;
            }
            if (s){
                
                cout << n << '\n';
                break;
            }
            n++;
        }
    }
}