#include<bits/stdc++.h> 

using namespace std; 
#define int long long
main() { 
	int n, M;
	cin >> n >> M;
	vector <int> t(n);
	for(int i = 0; i < n; i++)
	{
		cin >> t[i];
	}
	for(int i = 0; i < n; i++)
	{
		if(i == 0)
		{
			cout << 0 << " ";
		}
		else
		{
			vector <int> T;
			for(int j = 0; j < i; j++)
			{
				T.push_back(t[j]);
			}
			sort(T.begin(), T.end());
			int cnt = T.size(), sum = 0;
			for(int j = 0; j < T.size(); j++)
			{
				if(sum + T[j] > M - t[i])
				{
					break;
				}
				cnt--;
				sum += T[j];
			}
			cout << cnt << " ";
		}
	}
	return 0;
}