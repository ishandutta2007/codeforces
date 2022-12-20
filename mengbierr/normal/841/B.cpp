#include <bits/stdc++.h>

using namespace std;

#define int long long int

const int maxn=2e6;
int a[maxn];

main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;

    int cnt=0;
    int cnt2=0;

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt+=a[i];
        if(a[i]%2==1)
            cnt2++;
    }

    if(cnt%2==1)
        cout<<"First";
    else
    {
        if(cnt2>0)
            cout<<"First";
        else
            cout<<"Second";
    }


    return 0;
}