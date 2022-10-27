#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n, m, k;
		cin >> n >> m >> k;
		vector <int> A(n);
		for(int j = 0; j < n; j++)
		{
			cin >> A[j];
		}
		int cnt = m;
		bool flag = true;
		for(int j = 0; j < n - 1; j++)
		{
			int e = max(A[1 + j] - k, 0);
			if(A[j] < e)
			{
				if(cnt + A[j] < e)
				{
					flag = false;
					break;
				}
				else
				{
					cnt -= e - A[j];
				}
			}
			else
			{
				cnt += A[j] - e;
			}
		}
		if(flag){
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
	return 0;
}