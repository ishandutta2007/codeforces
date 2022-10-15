#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	cin>>a>>b;
	if(a.size()!=b.size())
	{
		cout<<"NO"<<endl;
		return 0;
	}
	int s=a.size();
	for(int i=0;i<s;i++)
		if(a[i]!=b[s-i-1])
		{
			cout<<"NO"<<endl;
			return 0;
		}
	cout<<"YES"<<endl;
	return 0;
}