#pragma gcc optimize("O3");
#pragma gcc target("SSE4");
#include <bits/stdc++.h> 
using namespace std;
const int inf = 1e9;
int main()
{
	int n, count = 0;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i < n; i++)
	{
		if(A[i] == 1)
		{
			if(i > 0 && A[i - 1] == 1)
			{
				count++;
			}
			else
			{
				count+=2;
			}
		}
	}
	if(count == 0)
	{
		count = 1;
	}
	cout << count - 1;
	return 0;
}