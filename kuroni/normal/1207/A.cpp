#include <bits/stdc++.h>
using namespace std;

int t, b, p, f, h, c;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> b >> p >> f >> h >> c;
        if (h < c)
        {
            swap(p, f);
            swap(h, c);
        }
        int tmp = min(b / 2, p);
        b -= tmp * 2;
        cout << tmp * h + min(b / 2, f) * c << '\n';
    }
}