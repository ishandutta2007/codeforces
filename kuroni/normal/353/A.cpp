#include <bits/stdc++.h>

using namespace std;

main()
{
    int a,b,upper,lower,n,i;
    bool diff = false;
    cin>>n;
    for (i = 0; i < n; i++)
    {
        cin>>a>>b;
        upper += a;
        lower += b;
        diff = diff || (((a - b) % 2) != 0);
    }
    if (((upper + lower) % 2) != 0) cout<<"-1";
    else
    {
        if ((upper % 2) == 0) cout<<"0"; else if (diff) cout<<"1"; else cout<<"-1";
    }
}