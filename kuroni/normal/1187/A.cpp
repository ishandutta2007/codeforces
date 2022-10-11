#include <bits/stdc++.h>
using namespace std;

int te, n, s, t;

int main()
{
    cin >> te;
    while (te--)
    {
        cin >> n >> s >> t;
        cout << n - min(s, t) + 1 << '\n';
    }
}