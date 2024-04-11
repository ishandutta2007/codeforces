#include<iostream>
#include<set>
using namespace std;
int ans,x,n;
set<int> s;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		if (x==i) ans++;
		else s.insert(x); 
	}
	cout<<ans+s.size()/2;
	return 0;
}