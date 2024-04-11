#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int n,k,i,j,l,a,b,c,d,count1=0;
  cin>>n>>k>>l;
  long long int arr1[n];
  for(i=0;i<n;i++)
  {
      cin>>arr1[i];
  }
  sort(arr1,arr1+n);
  a=arr1[l]-arr1[l-1];
  cout<<a;
}