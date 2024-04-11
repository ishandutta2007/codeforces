#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		string s;
		cin >> s;
		vector <int> pred(s.size());
		int pr = -1;
		int cnt = 0;
		for(int j = 0; j < s.size(); j++)
		{
			pred[j] = pr;
			int k = j;
			int sum = 0;
			if(s[j] == '1')
			{
				sum = 1;
			}
			for(int p = 1; p <= log2(s.size()) + 1; p++)
			{
				if(pred[k] == -1)
				{
					if(sum <= j + 1 && sum >= j - k + 1)
					{
						cnt++;
					}
				}
				else
				{
					if(sum < j - pred[k] + 1 && sum >= j - k + 1)
					{
						cnt++;
					}
					sum += pow(2, j - pred[k]);
				}
				k = pred[k];
				if(k == -1 || j - k > log2(s.size()))
				{
					break;
				}
			}
			if(s[j] == '1')
			{
				pr = j;
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}