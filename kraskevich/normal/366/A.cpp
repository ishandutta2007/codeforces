#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < 4; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for (int f = 1; f < n; f++)
        {
            int s = n - f;
            if (f >= min(a, b) && s >= min(c, d))
            {
                cout << i + 1 << " " << f << " " << s;
                return 0;
            }
        }
    }
    cout << -1;

    return 0;
}