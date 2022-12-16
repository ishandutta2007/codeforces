#include<bits/stdc++.h>
using namespace std;
const int nmax=50;
int n,arr[nmax];
int main()
{
cin>>n;
for(int i=0;i<n;i++)cin>>arr[i];
bool can=0;
for(int i=0;i<(1<<n);i++)
{
    int s=0;
    for(int j=0;j<n;j++)
        if((i&(1<<j)))s=s+arr[j];
        else s=s-arr[j];
    if(s%360==0)can=1;
}
if(can)cout<<"Yes"<<endl;
else cout<<"No"<<endl;
return 0;
}