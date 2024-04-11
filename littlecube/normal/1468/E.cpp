#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n[4];
        cin >> n[0] >> n[1] >> n[2] >> n[3];
        sort(n, n + 4);
        cout << min(n[0], n[1]) * min(n[2], n[3]) << '\n';
    }
}