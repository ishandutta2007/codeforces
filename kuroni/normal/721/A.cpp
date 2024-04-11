#include <iostream>
using namespace std;
main()
{
    bool cur = 0;
    int n, ans = 0, a[100], i;
    string s;
    cin>>n>>s;
    for (i = 0; i < n; i++)
    {
        if (s[i] == 'W') cur = 0;
        else
        {
            if (cur) a[ans]++; else a[++ans] = 1, cur = 1;
        }
    }
    cout<<ans<<'\n';
    for (i = 1; i <= ans; i++) cout<<a[i]<<" ";
}