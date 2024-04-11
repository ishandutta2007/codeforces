#include <bits/stdc++.h>
using namespace std;
main()
{
    int a, b, ans=0;
    bool c = true;
    cin>>a>>b;
    while (c)
    {
        if ((a== 1)&&(b==1)||(a==0)||(b==0)) break;
        if (a>b) swap(a,b);
        a++;
        b -= 2;
        c = (b > 0);
        ans++;
    }
    cout<<ans;
}