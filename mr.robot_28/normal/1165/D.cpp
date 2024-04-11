#include <bits/stdc++.h>

using namespace std;
#define int long long
int nod(int a, int b)
{
	if(a * b == 0)
	{
		return a + b;
	}
	else if(a > b)
	{
		return nod(a % b, b);
	}
	else
	{
		return nod(a, b % a);
	}
}
signed main() {
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		vector <int> A(n);
		for(int j = 0; j < n; j++)
		{
			cin >> A[j];
		}
		if(n == 1)
		{
			bool flag = true;
			for(int j = 2; j <= sqrt(A[0]); j++)
			{
				if(A[0] % j == 0)
				{
					flag = false;
					break;
				}
			}
			if(!flag)
			{
				cout << -1 << endl;
			}
			else
			{
				cout << A[0] * A[0] << endl;
			}
		}
		else
		{
			sort(A.begin(), A.end());
			int nok = A[0];
			bool flag = true;
			for(int j = 1; j < n; j++)
			{
				int d = nod(nok, A[j]);
				nok = nok * A[j] / d;
				if(nok > A[0] * A[n - 1])
				{
					flag = false;
					cout << -1 << endl;
					break;
				}
			}
			if(flag)
			{
				int nok1 = nok;
				int sum = 1, cn = 0;
				for(int j = 2; j <= sqrt(nok); j++)
				{
					int cnt = 0;
					while(nok1 % j == 0)
					{
						nok1 = nok1 / j;
						cnt++;
					}
					if(cnt != 0)
					{
						cn++;
					}
					sum = sum * (cnt + 1);
				}
				if(nok1 != 1)
				{
					sum *= 2;
					cn++;
				}
				bool fl = true;
				if(nok == A[A.size() - 1] && cn == 1)
				{
					sum++;
					nok *= A[0];
				}
				else if(nok == A[A.size() - 1])
				{
					fl = false;
					cout << -1 << endl;
				}
				if(n + 2 == sum && fl)
				{
					cout << nok << endl;
				}
				else if(fl)
				{
					cout << -1 << endl;
				}
			}
		}
	}
	return 0;
}