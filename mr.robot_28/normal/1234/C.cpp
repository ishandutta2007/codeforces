#include<bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		int n;
		cin >> n;
		string s1, s2;
		cin >> s1 >> s2;
		pair <int, int> pred = {0, 0}, a = {1, 0};
		while(a.first <= n && a.second >= 0 && a.second <= 1)
		{
		//	cout << a.first << " " << a.second << "\n";
			if(pred.second == a.second)
			{
				if(a.second == 0)
				{
					if(s1[a.first - 1] >= '1' && s1[a.first - 1] <= '2')
					{
						pred = a;
						a = {a.first + 1, a.second};
					}
					else
					{
						pred = a;
						a = {a.first, 1 - a.second};
					}
				}
				else
				{
					if(s2[a.first - 1] >= '1' && s2[a.first - 1] <= '2')
					{
						pred = a;
						a = {a.first + 1, a.second};
					}
					else
					{
						pred = a;
						a = {a.first, 1 - a.second};
					}
				}
			}
			else if(pred.second < a.second)
			{
				if(s2[a.first - 1] >= '3' && s2[a.first - 1] <= '6')
				{
					pred = a;
					a = {a.first + 1, a.second};
				}
				else
				{
					break;
				}
			}
			else
			{
				if(s1[a.first - 1] >= '3' && s1[a.first - 1] <= '6')
				{
					pred = a;
					a = {a.first + 1, a.second};
				}
				else
				{
					break;
				}
			}
		}
		if(a.first == n + 1 && a.second == 1)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
    return 0;
}