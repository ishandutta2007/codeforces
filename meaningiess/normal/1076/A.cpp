#include<iostream>
using namespace std;
char a[200010];
int main()
{
	int n,i,j;cin>>n;
	cin>>a;
	for (i=0;i<n-1;i++) if (a[i]>a[i+1]) break;j=i;
	for (i=0;i<j;i++) cout<<a[i];
	for (i=j+1;i<n;i++) cout<<a[i];
}