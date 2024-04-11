#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n[4], sn;
        cin >> n[0] >> n[1] >> n[2] >> n[3];
        sn = n[0] + n[1];

        if (sn % 2)
        {
            if (n[0] + n[3] == 0)
                cout << "Tidak ";
            else
                cout << "Ya ";

            if (n[1] + n[2] == 0)
                cout << "Tidak ";
            else
                cout << "Ya ";

            cout << "Tidak Tidak\n";
        }
        else
        {
            cout << "Tidak Tidak ";

            if (n[1] + n[2] == 0)
                cout << "Tidak ";
            else
                cout << "Ya ";

            if (n[0] + n[3] == 0)
                cout << "Tidak\n";
            else
                cout << "Ya\n";
        }
    }
}