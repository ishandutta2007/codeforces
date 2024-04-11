#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100001],b[100001],c[100001];
main()
{
    int n;
    cin>>n;
    for(int x=1;x<n;x++)
    cin>>c[x];
    int r=1,ans=0;
    b[1]=n;
    for(int x=n-1;x;x--)
    {
        auto q=*lower_bound(b+1,b+1+r,c[x],greater<int>());
        ans+=(a[x]=a[q]-c[x]+q+n-x);
        while(r&&c[b[r]]<=c[x])r--;
        b[++r]=x;
    }
    cout<<ans<<endl;
}