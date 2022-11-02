#include<bits/stdc++.h>
using namespace std;
int n,mini=0,maxi=2e9,i;
int a[500000];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<min(a[n]-a[2],a[n-1]-a[1]);
}