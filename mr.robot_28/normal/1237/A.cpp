#include <bits/stdc++.h>
using namespace std;
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> A(n);
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		if(abs(A[i]) % 2 != 0)
		{
			if(A[i] >= 0 && sum >= 0)
			{
				sum--;
				cout << A[i] / 2 << " ";
			}
			else if(A[i] >= 0 && sum <= 0)
			{
				sum++;
				cout << (A[i] + 1) / 2 << " ";
			}
			else if(A[i] <= 0 && sum >= 0)
			{
				sum--;
				cout << (A[i] - 1) / 2 << " ";
			}
			else
			{
				sum++;
				cout << A[i] / 2 << " ";
			}
		}
		else
		{
			cout << A[i] / 2 << " ";
		}
	}
  	return 0;
}