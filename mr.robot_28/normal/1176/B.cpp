#include<iostream>
#include <bits/stdc++.h> 
#include<vector>
#include<set>
using namespace std;
int main()
{
	#define int long long
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		vector <int> A(n);
		int cnt1 = 0, cnt2 = 0, cnt3 = 0;
		for(int j = 0; j < n; j++)
		{
			cin >> A[j];
			if(A[j] % 3 == 0)
			{
				cnt3++;
			}
			else if(A[j] % 3== 1)
			{
				cnt1++;
			}
			else
			{
				cnt2++;
			}
		}
		int u = min(cnt1, cnt2);
		cnt1 -= u;
		cnt2 -= u;
		cout << cnt3 + u + cnt1 / 3 + cnt2 / 3  << endl;
	}
	return 0;
}