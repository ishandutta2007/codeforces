#include<bits/stdc++.h>
using namespace std;

signed main() {
	#define int long long
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> cnt(64);
		vector <int> cnt1(64);
		vector <int> A(n);
		int b = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> A[i];
			b += A[i];
			int j = 0;
			while(A[i] > 0)
			{
				cnt[j] += A[i] % 2;
				j++;
				A[i] = A[i] / 2;
			}
		}
		int u = 0;
		for(int i = 0; i < 64; i++)
		{
			if(i == 0)
			{
				if(b % 2 == 1)
				{
					u += 1;
					b++;
					cnt[i]++;
				}
			}
			else
			{
				if(b % 2 != cnt[i - 1] % 2)
				{
					b += 1;
					cnt[i]++;
					u += pow(2, i);
				}
			}
			b = b / 2;
		}
		cout << 1 << "\n";
		cout << u << "\n";
	}
    return 0;
}