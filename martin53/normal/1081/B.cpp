#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;
pair<int/*value*/,int/*index*/> arr[nmax];
int b[nmax];
void no()
{
    cout<<"Impossible"<<endl;
    exit(0);
}
int main()
{
cin>>n;
for(int i=1;i<=n;i++)
{
    cin>>arr[i].first;
    arr[i].first=n-arr[i].first;
    arr[i].second=i;
}
sort(arr+1,arr+n+1);
int c=0;
for(int i=1;i<=n;i++)
{
    int r=i+arr[i].first-1;
    if(r>n)no();
    if(arr[r].first!=arr[i].first)no();
    c++;
    for(int j=i;j<=r;j++)
        b[arr[j].second]=c;
    i=r;
}
cout<<"Possible"<<endl;
for(int i=1;i<=n;i++)
    cout<<b[i]<<" ";cout<<endl;
return 0;
}