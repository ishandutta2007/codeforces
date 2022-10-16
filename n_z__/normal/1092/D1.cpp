#include<bits/stdc++.h>
using namespace std;
int a[2000001],t;
main()
{
    int n;
    cin>>n;
    for(int x=1;x<=n;x++)
    {
        cin>>a[++t],a[t]%=2;
        while(t>1&&a[t]==a[t-1])t-=2;
    }
    if(t<2)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}