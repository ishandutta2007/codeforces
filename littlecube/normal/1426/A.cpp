#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;
vector<int> p;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        cout << max(1, ((n - 2) + (x - 1)) / x + 1) << '\n';
    }
}