#include <bits/stdc++.h>

using namespace std;
int a[4];
int main()
{
    int k = 1, y, ans = 0;
    cin >> y >> a[1];
    a[2] = a[1];
    a[3] = a[1];
    while (a[1] != y || a[2] != y || a[3] != y)
    {

        if (k == 1)
        {
            if (a[1] != y)
            {
                while(1 == 1)
                {
                    if (abs(a[1] + 1 - max(a[2],a[3]) >= min(a[2], a[3])))
                        break;
                    if (a[1] == y)
                        break;
                    a[1] ++;
                }
                ans ++;
                k = 2;
            }
            k = 2;
        }
else
        if (k == 2)
        {
            if (a[2] != y)
            {
                while(1 == 1)
                {  // cout << a[2]<<endl;
                    if (abs(a[2]+1 - max(a[1],a[3]) >= min(a[1], a[3])))
                        break;
                    if (a[2] == y)
                        break;
                    a[2]++;
                }
                ans ++;
                k = 3;
            }
            k = 3;
        }
else
        if (k == 3)
        {
            if (a[3] != y)
            {
                while(1 == 1)
                {
                    if (abs(a[3]+1 - max(a[2],a[1]) >= min(a[2], a[1])))
                        break;
                    if (a[3] == y)
                        break;
                    a[3] ++;
                }
                ans ++;
                k = 1;
            }
            k = 1;
        }
    //cout << a[1]<<' '<<a[2]<<' '<<a[3]<<' '<<k<<ans<<endl;
    }
    cout << ans;
    return 0;
}