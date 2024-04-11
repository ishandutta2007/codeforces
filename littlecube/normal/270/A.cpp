#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n, tmp;
    cin >> n;
    while (n--)
    {
        cin >> tmp;
        if (360 % (180 - tmp))
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}