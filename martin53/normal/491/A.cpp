#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,a,b;
int arr[nmax];
int main()
{
cin>>a>>b;
n=a+b+1;
arr[a+1]=n;
for(int i=a;i>=1;i--)
    arr[i]=n-(a+1-i);
for(int i=a+2;i<=n;i++)
    arr[i]=arr[1]-(i-a-1);
for(int i=1;i<=n;i++)cout<<arr[i]<<" ";cout<<endl;
return 0;
}