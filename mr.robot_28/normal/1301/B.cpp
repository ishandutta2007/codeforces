#include <bits/stdc++.h>
 
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		vector <int> A(n);
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
		}
		int max1 = 0, min1 = 1e9;
		int ans1 = 0;
		for(int i = 0; i < n; i++)
		{
			if(i != 0 && A[i] == -1 && A[i - 1] != -1)
			{
				max1 = max(max1, A[i - 1]);
				min1 = min(min1, A[i - 1]);
			}
			if(i != n - 1 && A[i] == -1 && A[i + 1] != -1)
			{
				max1 = max(max1, A[i + 1]);
				min1 = min(min1, A[i + 1]);
			}
			if(i != n - 1 && A[i + 1] != -1 && A[i] != -1)
			{
				ans1 = max(ans1, abs(A[i + 1] - A[i]));
			}
		}
		if(max1 < min1)
		{
			cout << 0 << " " << 0 << "\n";
			continue;
		}
		int midd = (max1 + min1) / 2;
		ans1 = max(ans1, abs(max1 - midd));
		ans1 = max(ans1, abs(min1 - midd));
		cout <<ans1 << " " << midd << "\n";
	}
    return 0;
}