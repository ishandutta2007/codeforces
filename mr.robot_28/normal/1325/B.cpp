#include<bits/stdc++.h>
using namespace std;
#define int long long

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
		set <int> t;
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
			t.insert(A[i]);
		}
		cout << t.size() << "\n";
	}
	return 0;
}