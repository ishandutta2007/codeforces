#include<bits/stdc++.h>
using namespace std;
int main()
{
long long n,k;
cin>>n>>k;
if(n>=k)
{
    cout<<(k-1)/2<<endl;
    return 0;
}
if(n+(n+1)<k)
{
    cout<<0<<endl;
    return 0;
}
long long ans=n-(k-n)+1;
if(ans%2)ans--;
ans=ans/2;
cout<<ans<<endl;
return 0;
}