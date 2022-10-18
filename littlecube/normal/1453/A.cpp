#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n, r = 0;
        bool b[110] = {0};
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            b[tmp] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            int tmp;
            cin >> tmp;
            if(b[tmp])
                r++;
        }
        cout << r << '\n';
    }
}