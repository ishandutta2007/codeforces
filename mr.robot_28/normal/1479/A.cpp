#include<bits/stdc++.h>
using namespace std;
int n;
int get(int a)
{
    if(a == 0 || a == n + 1)
    {
        return 1e9;
    }
    cout << "? " << a << endl;
    int val;
    cin >> val;
    return val;
}
signed main()
{
 //   ios_base::sync_with_stdio(0);
   // cin.tie(0);
    //cout.tie(0);
    cin >> n;
    int l = 1, r = n;
    while(r > l)
    {
        int midd = (r + l) / 2;
        int v1 = get(midd - 1);
        int v2 = get(midd);
        int v3 = get(midd + 1);
        if(v1 > v2 && v2 < v3)
        {
            r = l = midd;
            break;
        }
        if(v2 > v3)
        {
            l = midd + 1;
        }
        else
        {
            r = midd;
        }
    }
    cout << "! " << l << endl;
    return 0;
}