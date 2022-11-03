#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll t, x ,s;
int main()
{
    cin >> t >> x >> s;
    if(s < t)
    {
        cout << "NO";
        return 0;
    }
    s-=t;
    if(s % x == 0 || s % x == 1 && s >= x)
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
}