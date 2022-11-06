#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pb push_back
using namespace std;
vector <char> z;
int main()
{
    string x, y;
    cin >> x >> y;
    for (int i = 0; i < x.size(); i++)
    {
        if (y[i] > x[i])
        {
            cout << -1;
            return 0;
        }
        if (y[i] == x[i])
            z.pb(x[i]);
        if (y[i] < x[i])
            z.pb(y[i]);
    }
    for (int i = 0; i < z.size(); i++)
        cout << z[i];
    return 0;
}