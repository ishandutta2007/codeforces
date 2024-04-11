#include <bits/stdc++.h>
using namespace std;
int n,a[30];
int main() 
{
	int Min=INT_MAX;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],Min=min(a[i],Min);
	cout<<(a[3]^Min)+2<<endl;
	return 0;
}