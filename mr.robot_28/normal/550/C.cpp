#include <iostream>
#include<vector>
#include<stack>
#include<utility>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	string a;
	cin >> a;
	vector <vector <bool> > dp(a.size(), vector <bool> (8));
	vector <vector <pair <int, int> > > prev(a.size(), vector <pair <int, int> > (8));
	for(int i = 0; i < a.size(); i++)
	{
		int r = a[i]- '0';
		for(int j = 0; j < i; j++)
		{
			for(int a1 = 0; a1 < 8; a1++)
			{
				if(dp[j][a1])
				{
				dp[i][(r + a1 * 10) % 8] = true; prev[i][(r + a1* 10) % 8] = {j, a1};
				//cout << prev[i][(r + a1 * 10) % 8].second << " ";
				}
			}
			//cout << endl;
		}
		dp[i][r % 8] = true;
		prev[i][r % 8] = {-1, -1};
	}
	pair <int, int> v;
	v.first = -1;
	v.second = -1;
	int pred = -1;
	for(int i = a.size() - 1; i >= 0; i--)
	{
		if(dp[i][0])
		{
			v = prev[i][0];
			pred = i;
			break;
		}
	}
	if(pred != -1)
	{
		cout << "YES";
		stack <pair <int, int> > w;
		while(v.first != -1)
		{
			w.push(v);
			if(prev[v.first][v.second].first == v.first)
			{
				break;
			}
			v = prev[v.first][v.second];
		}
		cout << endl;
		while(!w.empty())
		{
			cout << a[w.top().first];
			w.pop();
		}
		cout << a[pred] - '0';
	}
	else
	{
		cout << "NO";
	}
    return 0;
}