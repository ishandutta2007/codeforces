#include<bits/stdc++.h>
using namespace std;
#define int long long
const int const1 = 998244353;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int j = 0;
	int sum = 0;
	for(int i = 0; i < A.size(); i++)
	{
		if(A[j] < A[i])
		{
			sum++;
			j++;
		}
	}
	cout << sum;
	return 0;
}