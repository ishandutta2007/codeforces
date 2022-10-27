#include <bits/stdc++.h>
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
		vector <int> mass = {2, 3, 5, 7, 11, 13, 17, 19, 23 ,29, 31};
		vector <int> colored(n, 0);
		int cnt = 0;
		vector <int> used;
		for(int i = 0; i < 11; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(A[j] % mass[i] == 0 && !colored[j])
				{
					colored[j] = i + 1;
					used.push_back(i + 1);
				}
			}
		}
		int m = unique(used.begin(), used.end()) - used.begin();
		cout << m << "\n";
		for(int i = 0; i < n; i++)
		{
			colored[i] = lower_bound(used.begin(), used.begin() + m, colored[i]) - used.begin();
			cout << colored[i] + 1 << " ";
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(colored[i] == colored[j] && __gcd(A[i], A[j]) == 1)
				{
					cout << "NO";
				}
			}
		}
		cout << "\n";
	}
    return 0;
}