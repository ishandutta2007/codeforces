#include <bits/stdc++.h>
using namespace std;
main()
{
    int a[1001],tmp,ans=0,n,i=0;
    bool b[1001];
    memset(a,0,sizeof(a));
    memset(b,false,sizeof(b));
    for(cin>>n;i<n;i++)
    {
        cin>>tmp;
        a[tmp]++;
        ans += b[a[tmp]];
        b[a[tmp]] = true;
    }
    cout<<ans;
}