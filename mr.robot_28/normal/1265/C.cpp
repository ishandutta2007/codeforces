#include <bits/stdc++.h>
using namespace std;
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> A(n);
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		int j = 0;
		int gr = 0, gs = 0, gb = 0;
		bool flag = true;
		while(gr < n && A[gr] == A[0])
		{
			gr++;
		}
		gr--;
		if(gr == n - 1)
		{
			flag = false;
		}
		gs = 2 * gr + 2;
		while(gs < n && A[gs] == A[2 * gr + 2])
		{
			gs++;
		}
		gs--;
		if(gs >= n / 2)
		{
			flag = false;
		}
		gb = gs + gr + 2;
		while(gb < n && A[gb] == A[gs + gr + 2])
		{
			gb++;
		}
		gb--;
		if(gb >= n / 2 || !flag)
		{
			cout << 0 << " " << 0 << " " << 0 << "\n"; 
		}
		else
		{
			for(int t = gb + 1; t < n / 2; t++)
			{
				if(A[t + 1] != A[t])
				{
					gb = t;
				}
			}
			cout << gr + 1 << " " << gs - gr << " " <<gb - gs << "\n";
		}
	}
    return 0;
}