#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	cin >> m;
	vector <int> B(m);
	for(int j = 0; j < m; j++)
	{
		cin >> B[j];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	int j = 0, count = 0;
	for(int i = 0; i < n; i++)
	{
		while(j < m && A[i] - B[j] > 1)
		{
			j++;
		}
		if(j < m && abs(A[i] - B[j]) <= 1)
		{
			j++;
			count++;
		}
	}
	cout << count;
    return 0;
}