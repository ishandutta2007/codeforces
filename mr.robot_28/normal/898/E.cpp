#pragma gcc optimize("O3");
#pragma gcc target("SSE4");
#include <bits/stdc++.h> 
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <long long> A, B;
	for(int i = 0; i < n; i++)
	{
		long long a;
		cin >> a;
		long long y = sqrt(a);
		if(y * y == a)
		{
			A.push_back(a);
		}
		else
		{
			B.push_back(a);
		}
	}
	if(A.size() > B.size())
	{
		long long count = 0;
		sort(A.begin(), A.end());
		int i = A.size() - 1;
		while(A.size() > B.size())
		{
			if(A[i] == 0)
			{
				count+=2;
				A.erase(A.begin() + i);
				B.push_back(2);
				i--;
			}
			else
			{
				count += 1;
				B.push_back(A[i] + 1);
				A.erase(A.begin() + i);
				i--;
			}
		}
		cout << count;
	}
	else
	{
		vector <pair <long long, long long > > L(B.size());
		for(int i =0; i < B.size(); i++)
		{
			long long y = sqrt(B[i]);
			long long t = min(B[i] - y * y, (y + 1) * (y + 1) - B[i]);
			L[i].first = t;
			L[i].second = B[i];
		}
		long long count = 0;
		sort(L.begin(), L.end());
		for(int i = 0; i < (B.size() - A.size()) / 2; i++)
		{
			count += L[i].first;
		}
		cout << count;
	}
	return 0;
}