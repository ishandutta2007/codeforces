#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	int n, m;
	cin >> n >> m;
	vector <vector <int> > A(n, vector <int> (m));
	int i = 1;
	while(i <= (n + 1) / 2)
	{
		int j = 1;
		while(j <= m)
		{
			if(m - j + 1 >= j || i != n - i + 1)
			{
			cout << i << " " << j << "\n";
			}
			if(m - j + 1 > j || i != n - i + 1)
			{
				cout << n - i + 1 << " " << m - j + 1<< "\n";
			}
			j++;
		}
		i++;
	}
    return 0;
}