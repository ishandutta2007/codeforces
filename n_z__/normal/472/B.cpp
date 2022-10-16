#include<bits/stdc++.h>
using namespace std;
int a[2001];
int main()
{
    int n,k;
    cin>>n>>k;
    for (int x=1;x<=n;x++)
    cin>>a[x];
    sort(a+1,a+1+n);
    int ans=0;
    for(int x=n;x>=1;x-=k)
    ans+=2*(a[x]-1);
    cout<<ans<<endl;
}