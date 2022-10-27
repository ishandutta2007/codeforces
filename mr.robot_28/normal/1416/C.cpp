#include<bits/stdc++.h>
using namespace std;
 
 
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> a(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	vector <vector <int> > mass;
	vector <vector <int> > mass1;
	mass1.push_back({});
	for(int i = 0; i < n; i++)
	{
		mass1[mass1.size() - 1].push_back(i);
	}
	long long allsum = 0;
	int minx = 0;
	for(int i = 29; i >= 0; i--){
		long long sum1 = 0, sum2 = 0;
		mass.clear();
		for(int j = 0; j < mass1.size(); j++)
		{
			int cnt0 = 0;
			int cnt1 = 0;
			vector <int> vec1, vec2;
			for(int k = 0; k < mass1[j].size(); k++)
			{
				if((a[mass1[j][k]] & (1 << i)) == 0)
				{
					vec1.push_back(mass1[j][k]);
					sum1 += cnt1;
					cnt0++;
				}
				else
				{
					vec2.push_back(mass1[j][k]);
					sum2 += cnt0;
					cnt1++;
				}
			}
			if(vec1.size() != 0)
			{
				mass.push_back(vec1);
			}
			if(vec2.size() != 0)
			{
				mass.push_back(vec2);
			}
		}
		allsum += min(sum1, sum2);
		if(sum1 > sum2)
		{
			minx |= (1 << i);
		}
		mass1.clear();
		for(int j = 0; j < mass.size(); j++)
		{
			mass1.push_back(mass[j]);
		}
	}
	cout << allsum << " " << minx << "\n";
	return 0;
}