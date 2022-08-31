#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
int n;
cin>>n;
int *a=new int[n];
int *b=new int[n];
for (int i=0;i<n;i++)
{
cin>>a[i];
b[i]=a[i];
}
sort(a,a+n);
int k=0;
for (int i=0;i<n;i++)
if (a[i]!=b[i]) k++;
if (k<=2) cout<<"YES"; else cout<<"NO";
cout<<endl;
return 0;
}