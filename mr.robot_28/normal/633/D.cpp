#include <bits/stdc++.h>
using namespace std;
signed main()
{
	int n;
	cin >> n;
	unordered_map <int, int> w;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		w[A[i]]++;
	}
	int ans = 0;
	set <pair <int, int> > s;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(i != j && s.find({A[i], A[j]}) == s.end())
			{
				s.insert({A[i], A[j]});
	unordered_map <int, int> w1;
				w1[A[i]]++;
				w1[A[j]]++;
				int a = A[i], b = A[j];
				if(a == 0 && b == 0)
				{
					ans = max(ans, w[0]);
				}
				else
				{
				int k = 0;
				for(k = 0; k < n - 2; k++)
				{
					a = a + b;
					swap(a, b);
					if(w[b] > w1[b])
					{
						w1[b]++;
					}
					else
					{
						break;
					}
				}
				k += 2;
				ans = max(ans, k);
			}
			}
		}
	}
	cout << ans;
	return 0;
}