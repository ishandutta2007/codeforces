#include <bits/stdc++.h>

using namespace std;


int main() {
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <string> A(n);
		vector <bool> used(10, false);
		for(int i = 0; i < n; i++){
			cin >> A[i];
			used[A[i][0] - '0'] = true;
		}
		int cnt = 0;
		int k = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = i + 1; j < n; j++)
			{
				if(A[j] == A[i])
				{
					while(k < 10 && used[k])
					{
						k++;
					}
					used[k] = true;
					cnt++;
					A[j][0] = k + '0';
				}
			}
		}
		cout << cnt << "\n";
		for(int i = 0; i < n; i++)
		{
			cout << A[i] << "\n";
		}
	}
	return 0;
}