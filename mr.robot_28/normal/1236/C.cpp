#include <bits/stdc++.h>

using namespace std;
#define int long long
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	int k = (n / 2) * n;
	int l = 0;
	for(int i = 0; i < n; i++){
		int j = 0;
		for(int k = 0; k < n; k++)
		{
			if(k % 2 == 0)
			{
				cout << i + j + 1 << " ";
			}
			else
			{
				cout << n - i + j << " ";
			}
			j += n;
		}
		cout << "\n";
	}
    return 0;
}