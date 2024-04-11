#include<bits/stdc++.h>
using namespace std;

signed main() {
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
		int l = -1, r = -1;
		for(int i = 0; i < n - 1; i++)
		{
			if(abs(A[i] - A[i + 1]) >= 2)
			{
				l = i + 1;
				r = i + 2;
			}
		}
		if(l == -1)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
			cout << l << " " << r << "\n";
		}
	}
    return 0;
}