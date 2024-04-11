#include <bits/stdc++.h>
using namespace std;

int b, g, n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> b >> g >> n;
    b = n - min(b, n); g = min(g, n);
    cout << abs(g - b) + 1;
}