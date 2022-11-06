#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;


int n, p[1001], a[1001], b[1001], kol = 0;
bool used[1001];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != b[i])
            kol++;
    }
    if (kol == 1)
    {
        int pp = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == b[i])
            {
                p[i] = a[i];
                used[a[i]] = true;
            }
            else
            {
                pp = i;
            }
        }
        for (int i = 1; i <= n; i++)
            if (!used[i])
                p[pp] = i;

    }
    if (kol == 2)
    {
        int p1, p2, k = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == b[i])
              {
                p[i] = (a[i]);
                used[a[i]] = true;
              }
            else
                if (k == 0)
                 {
                     k = 1;
                     p1 = i;
                 }else
                 p2 = i;
        if (!used[a[p2]] && !used[b[p1]])
{
            p[p2] = a[p2];
             p[p1] = b[p1];
}
        else
         {
             p[p1] = a[p1];
            p[p2] = b[p2];
         }

    }
    for (int i = 1; i <= n; i++)
        cout << p[i] << ' ' ;
    return 0;
}