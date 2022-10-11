#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v[3];
int ptr[3];
int main()
{
	int n,cnta=0,cntb=0,sum=0;
	cin >> n;
	for (int i=0;i<n;i++)
	{
		string s;
		int a,idx=0;
		cin >> s >> a;
		if (s[0]=='1')
		idx+=2;
		if (s[1]=='1')
		idx++;
		if (idx==3)
		{
			cnta++;
			cntb++;
			sum+=a;
		}
		else
		v[idx].push_back(a);
	}
	for (int i=0;i<3;i++)
	{
		sort(v[i].begin(),v[i].end());
		ptr[i]=(int)v[i].size()-1;
	}
	int cur=cnta;
	while (ptr[1]>=0 && ptr[2]>=0)
	{
		sum+=v[1][ptr[1]];
		sum+=v[2][ptr[2]];
		ptr[1]--;
		ptr[2]--;
		cur+=2;
		cnta++;
		cntb++;
	}
	while (1)
	{
		pair<int,int> p(-1,-1);
		for (int i=0;i<3;i++)
		{
			if (ptr[i]!=-1)
			p=max(p,{v[i][ptr[i]],i});
		}
		if (p.second==-1)
		break;
		if (p.second==1)
		cnta++;
		else if (p.second==2)
		cntb++;
		cur++;
		if (2*cnta<cur || 2*cntb<cur)
		break;
		sum+=v[p.second][ptr[p.second]];
		ptr[p.second]--;
	}
	cout << sum;
}