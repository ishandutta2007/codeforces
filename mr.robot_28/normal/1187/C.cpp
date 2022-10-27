#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	vector <int> used(n, 0);
	vector <pair<int, int> > T;
	for(int i = 0; i < m; i++)
	{
		int t, l, r;
		cin >> t >> l >> r;
		if(t == 1)
		{
			int k = l - 2;
			if(k >= 0 && used[k] > 0)
			{
				while(k >= 0 && used[l - 1] == used[k])
				{
					used[k] = i + 1;
					k--;
				}
			}
			k = r;
			if(k < n && used[k] > 0)
			{
				while(k < n && used[r - 1] == used[k])
				{
					used[k] = i + 1;
					k++;
				}
			}
			for(int j = l - 1; j <= r - 1; j++)
			{
				used[j] = i + 1;
			}
		}
		else
		{
			for(int j = l - 1; j <= r - 1; j++)
			{
				if(used[j] == 0)
				{
					used[j] = -1;
				}
			}
			T.push_back({l - 1, r - 1});
		}
	}
	vector <int> A(n);
	for(int i = 0; i < T.size(); i++)
	{
		bool flag = false;
		for(int p = T[i].first; p <= T[i].second; p++)
		{
			if(used[p] != used[T[i].first] || used[p] < 0)
			{
				flag = true;
			}
		}
		if(!flag)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES" << endl;
	int st = 1;
	for(int i =  0; i < n; i++)
	{
		if(used[i] < 0 || i < n - 1 && used[i + 1] != used[i])
		{
			A[i] = st;
			st--;
		}
		else
		{
			A[i] = st;
			st++;
		}
	}
	int min = 0;
	for(int i = 0; i < n; i++){
		if(min > A[i])
		{
			min = A[i];
		}
	}
	for(int i = 0; i < n; i++)
	{
		A[i] -= min;
		A[i]++;
		cout << A[i] << " ";
	}
	return 0;
}