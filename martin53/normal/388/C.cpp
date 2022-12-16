#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+42;
int n;
int m,arr[nmax];
vector<int> spec;
int main()
{
long long f=0,s=0;
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>m;
    for(int j=1;j<=m;j++)cin>>arr[j];
    for(int j=1;j<=m/2;j++)
        f=f+arr[j],s=s+arr[m+1-j];
    if(m%2==1)spec.push_back(arr[(m+1)/2]);
}
sort(spec.begin(),spec.end());
int SZ=spec.size();
for(int j=SZ-1;j>=0;j--)
    if((SZ-j)%2==1)f=f+spec[j];
    else s=s+spec[j];
cout<<f<<" "<<s<<endl;
return 0;
}