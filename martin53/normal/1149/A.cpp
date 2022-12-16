#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n;
int arr[nmax];
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
cin>>n;
for(int i=1;i<=n;i++)cin>>arr[i];
sort(arr+1,arr+n+1,cmp);

for(int i=1;i<=n&&n!=1;i++)
    if(arr[i]==1)
        {swap(arr[2],arr[i]);break;}

for(int i=1;i<=n;i++)cout<<arr[i]<<" ";cout<<endl;
return 0;
}