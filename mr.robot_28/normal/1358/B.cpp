#include<bits/stdc++.h>
using namespace std;

signed main() {
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
		sort(A.begin(), A.end());
		int cnt = 1;
		int l = -1;
		for(int i = 0; i < n; i++)
		{
			if(i - l + cnt - 1 >= A[i])
			{
				cnt += i - l;
				l = i;
			}
		}
		cout << cnt << "\n";
	}
    return 0;
}