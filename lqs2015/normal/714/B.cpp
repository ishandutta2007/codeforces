#include<iostream>
#include<set>
using namespace std;
int n,x;
set<int> s;
int main()
{
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		s.insert(x);
	}
	if (s.size()>3) cout<<"NO"<<endl;
	else if (s.size()==3)
	{
		set<int>::iterator it=s.begin();
		int x=*it;
		it++;
		int y=*it;
		it++;
		int z=*it;
		if (z-y==y-x) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	else cout<<"YES"<<endl;
	return 0;
}