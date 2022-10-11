#include <iostream>
#include <limits.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(0);
    int n, c, prev, cur, ans = 1;
    cin>>n>>c>>prev;
    for (int i = 1; i < n; i++)
    {
        cin>>cur;
        if (cur - prev > c) ans = 1; else ans++;
        prev = cur;
    }
    cout<<ans;
}