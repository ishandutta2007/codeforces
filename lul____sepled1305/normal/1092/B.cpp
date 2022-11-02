#include<bits/stdc++.h>
using namespace std;
int n,change,i;
int a[110];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(i=1;i<=n/2;i++)
    {
        change+=a[2*i]-a[2*i-1];
    }
    cout<<change;
    return 0;
}