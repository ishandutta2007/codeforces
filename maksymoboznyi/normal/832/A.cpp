#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

ll n, k, a1, a2, a3;

int main()
{
    cin >> n >> k;
    a1 = n / k;
    if (a1 % 2 == 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}