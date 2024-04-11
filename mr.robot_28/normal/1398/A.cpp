#include<bits/stdc++.h>
 
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
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
		int a = -1, b = -1, c = -1;
		if(A[0] + A[1] <= A[n - 1])
		{
			a = 1;
			b = 2;
			c = n;
		}
		if(a == -1)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << a << " " << b << " " << c << "\n";
		}
	}
	return 0;
}