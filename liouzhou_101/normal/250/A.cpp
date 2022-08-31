#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

int n;
vector<int> p;

int main()
{
	cin>>n;
	int loss=0,have=0;
	for (int i=1;i<=n;++i)
	{
		int x;
		cin>>x;
		if (x>=0)
		{
			have++;
			continue;
		}
		else
		{
			if (loss==2)
			{
				p.push_back(have);
				loss=0;
				have=0;
			}
			have++;
			loss++;
		}
	}
	if (have>0) p.push_back(have);
	cout<<p.size()<<endl;
	for (int i=0;i<p.size();++i)
		cout<<p[i]<<" ";
	return 0;
}