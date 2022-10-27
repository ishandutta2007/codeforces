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
	int n, a, b;
	cin >> n;
	vector <bool> A(n, 0), B(n, 0);
	vector <int> W;
	for(int i = 0; i < n * n; i++)
	{
		cin >> a >> b;
		if(!A[a - 1] && !B[b - 1])
		{
			W.push_back(i + 1);
			A[a - 1] = B[b - 1] = true;
		}
	}
	for(int i = 0; i < W.size(); i++)
	{
		cout << W[i] << " ";
	}
	return 0;
}