#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	int m=-1;
	for(int l=0;l<n;l++)
	{
		if(m==-1 || (l+1)*(n-l)>m) m=(l+1)*(n-l);
	}
	cout<<m<<endl;
	return 0;
}