#include<bits/stdc++.h>
 
using namespace std;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long n;
	cin >> n;
	int q;
	cin >> q;
	while(q--)
	{
		long long x;
		cin >> x;
		long long l = 1, r = n;
		while(true)
		{
			if(x % 2 == 1)
			{
				cout << (x + 1) / 2 << "\n";
				break;
			}
			if((r - l + 1) % 2 == 1)
			{
				long long len = (r - l + 1);
				if(l % 2 == 0)
				{
					x = r + (x - l) / 2 + 1;
					l += len;
					r += (len + 1) / 2;
				}
				else
				{
					x = (x - l + 1) / 2 + r;
					l += len;
					r += len / 2;
				}
			}
			else
			{
				if(l % 2 == 1)
				{
					x = r + (x - l + 1) / 2; 
				}
				else
				{
					x = r + (x - l) / 2 + 1;
				}
				long long len = r - l + 1;
				l += len;
				r += len / 2;
			}
		}
	}
	return 0;
}