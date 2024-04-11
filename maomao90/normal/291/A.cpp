#include <bits/stdc++.h>
 
using namespace std;
 
int n, id[1000], ans;
 
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> id[i];
    }
 
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (id[i] == id[j] && id[j] == id[k] && id[i] != 0)
                {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }
 
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (id[i] == id[j] && id[i] != 0)
            {
                ans++;
            }
        }
    }
 
    cout << ans << '\n';
    return 0;
}