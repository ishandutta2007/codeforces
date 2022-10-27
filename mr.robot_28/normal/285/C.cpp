#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<string>
using namespace std;
int main()
{
	int n;
	long long count = 0;
	cin >> n;
	vector <long long> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	for(int i = 0; i < n; i++)
	{
		count += abs(i + 1 - A[i]);
	}
	cout << count;
	return 0;
}