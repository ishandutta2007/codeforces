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
		vector <int> a(n);
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int c = 1;
		int lev = 1;
		for(int i = 1; i < n;)
		{
	//		int d = i;
			int c2 = 0;
			//cout << c << " ";
			while(c > 0 && i < n)
			{
				int j = i;
				while(j < n - 1 && a[j + 1] > a[j])
				{
					j++;
				}
				c--;
				c2 += j - i + 1;
				i = j + 1;
			}
			c += c2;
			if(i == n)
			{
				cout << lev << "\n";
				break;
			}
			lev++;
		}
	}
	return 0;
}