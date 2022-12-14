#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		char a[n+1];
		cin>>a;
		int sum = 0;
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]==')') sum++;
			else break;
		}
		if(sum>(n-sum)) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}