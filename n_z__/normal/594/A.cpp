#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
    int n;
    cin>>n;
    for(int x=1;x<=n;x++)
    cin>>a[x];
    sort(a+1,a+1+n);
    int ans=1000000000;
    for(int x=1;x<=n/2;x++)
    ans=min(ans,a[x+n/2]-a[x]);
    cout<<ans<<endl;
}