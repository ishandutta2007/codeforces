#include<bits/stdc++.h> 
using namespace std;
int main () {
	int n, m, k;
	cin >> n >> m >> k;
	vector <pair <long long, int> > A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first;
		A[i].second = i;
	}
	long long sum = 0;
	sort(A.begin(), A.end());
	vector <int> ind(m * k);
	for(int i = n - 1; i >= max(n - m * k, 0); i--)
	{
		sum += A[i].first;
		ind[n - 1 - i] = A[i].second;
	}
	cout << sum << endl;
	sort(ind.begin(), ind.end());
	for(int i = 0; i < k - 1; i++)
	{
		cout << ind[(i + 1) * m - 1] + 1 << " ";
	}
	return 0;
}