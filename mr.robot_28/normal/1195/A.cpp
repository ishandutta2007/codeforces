#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	vector <int> A(n);
	vector <int> F(k);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		F[A[i] - 1]++;
	}
	int cnt = 0;
	bool flag = true;
	for(int i =0; i < k; i++)
	{
		if(F[i] % 2 != 0 && flag){
			cnt++;
			flag = false;
		}
		else if(F[i] % 2 != 0)
		{
			flag = true;
		}
		cnt += F[i] - F[i] % 2;
	}
	cout << cnt;
	return 0;
}