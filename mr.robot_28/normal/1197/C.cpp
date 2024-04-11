#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	vector <int> K;
	int ans = A[n - 1] - A[0];
	for(int i = 0; i < n - 1; i++)
	{
		K.push_back(A[i + 1] - A[i]);
	}
	sort(K.begin(), K.end());
	for(int i = 0; i < min(int(K.size()), k - 1); i++)
	{
		ans -= K[K.size() - 1 - i];
	}
	cout << ans;
	return 0;
}