#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int res = 0;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            if (!m)
                m++, res++;
            m--;
        }
        else
        {
            if (k)
            {
                k--;
                continue;
            }
            if (m)
            {
                m--;
                continue;
            }
            res++;
        }
    }
    cout << res;

    return 0;
}