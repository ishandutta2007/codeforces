#include<iostream>
#include<cmath>
#include<map>
#include<fstream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<queue>
#include<set>
using namespace std;
main()
{
	int n;
	cin >> n;
	vector <int> A(n), B(n);
	vector <int> used(n + 1, -1);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> B[i];
		used[B[i]] = i + 1;
	}
	if(used[1])
	{
		int u = 2;
		while(used[u] == used[1] + u - 1){
			u++;
		}
		if(used[u - 1] == n)
		{
			int j = u;
			while(j <= n && used[j] <= j - u)
			{
				j++;
			}
			if(j > n)
			{
				cout << n - u + 1;
				return 0;
			}
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
	{
		cnt = max(cnt, used[i] - i + 1);
	}
	cout << cnt + n;
	return 0;
}