#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;


int n, a[51][51];

int main()
{
    cin >> n;
    for (int x = 1; x <= n; x++)
        for (int j = 1; j <= n; j++)
            cin >> a[x][j];
    bool r = false;
    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++)
        {
            r = false;
            if (a[x][y] == 1)
                r = true;
            else
                for (int s = 1; s <= n; s++)
                  {
                      for (int t = 1; t <= n; t++)
                        if (a[x][y] == a[x][s] + a[t][y])
                        {
                            r = true;
                            break;
                        }
                    if (r)
                        break;
                  }
            if (!r)
            {
                cout << "No";
                return 0;
            }
        }
    cout << "Yes";
    return 0;
}