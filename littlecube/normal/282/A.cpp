#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n, x = 0;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (s[1] == '+')
            x++;
        else
            x--;
    }
    cout << x << '\n';
}