#include <bits/stdc++.h>

using namespace std;

int main() {
	#define int long long
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int h, n;
		cin >> h >> n;
		vector <int> p(n);
		for(int j = 0; j < n; j++)
		{
			cin >> p[j];
		}
		int cnt = 0;
		for(int j = 0; j < n; j++)
		{
			int j1 = j;
			while(j1 < n - 1 && p[j1 + 1] == p[j1] - 1)
			{
				j1++;
			}
			if((j != 0 && (j1 - j) % 2 == 0 || j == 0 && (j1 - j) % 2 == 1)&& p[j1] != 1)
			{
				cnt++;
			}
			j = j1;
		}
		cout << cnt << "\n";
	}
	return 0;
}