#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

int main()
{
    ll x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    if ((x1 - x2)%x == 0 && (y1-y2)%y == 0 && abs((x1-x2)/x)%2 == abs((y1-y2)/y)%2)

        cout <<  "YES";
    else
        cout <<  "NO";
    return 0;
}