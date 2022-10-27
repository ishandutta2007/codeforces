#include<bits/stdc++.h>
using namespace std;
int main()
{
	#define int long long
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		int r = (1 + sqrt(n * 8 + 1)) / 2;
		int cnt = n - r * (r - 1) / 2;
		vector <int> post;
		while(cnt > 0)
		{
			int x = (1 + sqrt(cnt * 8 + 1)) / 2;
			cnt -= x * (x - 1) / 2;
			post.push_back(x);
		}
		cout << "1";
		int j = 0, p = 0;
		while(j < r)
		{
			cnt++;
			if(p != post.size() && post[p] == r - j)
			{
				cout << "1";
				p++;
			}
			else
			{
				j++;
				cout << "3";
			}
		}
		cout << "7";
		cout << "\n";
	}
	return 0;
}