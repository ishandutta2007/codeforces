#pragma gcc optimize("O3");
#pragma gcc target("SSE4");
#include <bits/stdc++.h> 
using namespace std;
const int inf = 1e9;
int main()
{
	int n;
	cin >> n;
	vector <int> A;
	for(int i = 1; i < 90; i++)
	{
		int k = n - i, sum = 0;
		while(k > 0)
		{
			sum += k % 10;
			k = k / 10;
		}
		if(i == sum)
		{
			A.push_back(n - i);
		}
	}
	cout << A.size() << endl;
	sort(A.begin(), A.end());
	for(int i = 0; i < A.size(); i++)
	{
		cout << A[i] << endl;
	}
	return 0;
}