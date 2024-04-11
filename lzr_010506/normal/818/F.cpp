#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int main()
{
	int T;
	T = read();
	while(T --)
	{
		int n = read();
		if(n <= 5) {cout << n - 1 << endl; continue;}
		int l = 3, r = n;
		while(l < r - 1)
		{
			int mid = l + r >> 1;
			if((ll)(n - mid) * 2ll >= (ll)mid *(ll) (mid - 1) / 2ll + (ll)n - (ll)mid) l = mid;
			else r = mid;
		}
		cout << max((ll)l * (l - 1) / 2 + n - l, (ll)(n - r) * 2) << endl;
	}
	return 0;
}