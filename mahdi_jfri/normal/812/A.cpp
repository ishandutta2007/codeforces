#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int maxn = 1e5 + 20;
bool a[4][4];
int main()
{
    for(ll i = 0; i < 4; i++)
    {
        for(ll j = 0; j < 4; j++)
            cin >> a[i][j];
        if(a[i][3])
            if(a[i][2] || a[i][1] || a[i][0])
            {
                cout << "YES\n";
                return 0;
            }
    }
    if(a[0][3])
        if(a[1][0]||a[2][1]||a[3][2])
        {
            cout << "YES\n";
            return 0;
        }
    if(a[3][3])
        if(a[0][0]||a[1][1]||a[2][2])
        {
            cout << "YES\n";
            return 0;
        }
    if(a[1][3])
        if(a[0][2]||a[2][0]||a[3][1])
        {
            cout << "YES\n";
            return 0;
        }
    if(a[2][3])
        if(a[0][1]||a[1][2]||a[3][0])
        {
            cout << "YES\n";
            return 0;
        }
    cout << "NO";
    return 0;
}