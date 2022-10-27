#include <bits/stdc++.h>
using namespace std;
int main()
{
	#define int long long
	int n, k;
	cin >> n >> k;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int j = 0;
	for(int i = 0; i < k; i++)
	{
		if(i == 0)
		{
			cout << A[j] << "\n";
			j++;
		}
		else if(j >= n)
		{
			cout << 0 << "\n";
		}
		else
		{
			while(j < n && A[j] - A[j - 1] == 0){
				j++;
			}
			if(j == n)
			{
				cout << 0 << "\n";
			}
			else
			{
				cout << A[j] - A[j - 1] << "\n";
				j++;
			}
		}
	}
    return 0;
}