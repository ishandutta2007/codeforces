#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (x == 1 || x == 2 || x == 4 || x == 5 || x == 8 || x == 11)
            cout << "NO\n";
        else
            cout<< "YES\n";
    }
    return 0;
}