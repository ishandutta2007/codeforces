#include<bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
	cin>>n;
	vector<int> a(11);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		a[y]=max(a[y],x);
	}
	int sum=0;
	for(int i=1;i<=10;i++)
	{
		if(a[i]==0)
		{
			cout<<"MOREPROBLEMS"<<endl;
			return;
		}
		sum+=a[i];
	}
	cout<<sum<<endl;
}
int main()
{
	int T;
	cin>>T;
	while(T--)solve();
	return 0;
}