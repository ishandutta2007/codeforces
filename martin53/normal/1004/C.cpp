#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,a[nmax];
map<int,int> seen_right,seen_left;
int main()
{
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];
long long un=0;
for(int i=1;i<=n;i++)
    {
    if(seen_right.count(a[i])==0)un++;
    seen_right[a[i]]++;
    }
long long ans=0;
for(int i=1;i<=n;i++)
{
    if(seen_right[a[i]]==1)un--;
    seen_right[a[i]]--;
    if(seen_left.count(a[i])==0)
    {
        ans=ans+un;
    }
    seen_left[a[i]]=1;
}
cout<<ans<<endl;
return 0;
}