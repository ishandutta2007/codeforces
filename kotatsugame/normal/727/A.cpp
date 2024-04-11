#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int a,b;
	vector<int> ans;
	cin>>a>>b;
	while(b>=a*2&&b!=a)
	{
		if(b%2==0)
		{
			ans.push_back(b);
			b/=2;
			continue;
		}
		else if(b%10==1)
		{
			ans.push_back(b);
			b=(b-1)/10;
			continue;
		}
		else break;
	}
	if(a!=b)cout<<"NO"<<endl;
	else
	{
		ans.push_back(a);
		cout<<"YES"<<endl;
		cout<<ans.size()<<endl;
		for(int i=ans.size()-1;i>=0;i--)
		{
			cout<<ans[i];
			if(i)cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}