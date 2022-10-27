#include <bits/stdc++.h>
using namespace std;
int main()
{
	#define int long long
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		A[i] += 2 * n;
	}
	vector <pair <pair <int, int>, int> > W;
	cout << n + 1 << "\n";
	cout << 1 << " " << n << " " << 2 * n << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << 2 << " " << i + 1 << " " << A[i] - i << "\n";
	}
    return 0;
}