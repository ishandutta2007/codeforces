#include <bits/stdc++.h>
                  
using namespace std;
vector <int> ans;
int n;
void funct(int l, int r, set <pair <int, int> > s)
{
	cout << "? " << l + 1 << " " << r + 1 << endl;
	fflush(stdout);
	int f, x;
	cin >> x >> f;
	set <pair <int, int> > :: iterator it;
	it = s.lower_bound({x, 0});
	if(it != s.end() && it -> first == x)
	{
		for(int j = r; j > r - f; j--)
		{
			ans[j] = x;
		}
		s.erase(it);
		if(r - f >= l)
		{
			funct(l, r - f, s);
		}
	}
	else
	{
		s.insert({x, f});
		for(int i = l; i <= r; i += f)
		{
			funct(i, min(r, i + f - 1), s);
			it = s.lower_bound({ans[min(r, i + f - 1)], 0});
			if(it != s.end() && it -> first == ans[min(r, i + f - 1)])
			{
				int cnt = 0;
				for(int j = min(r, i + f - 1); j >= i; j--)
				{
					if(ans[j] != ans[min(r, i + f - 1)])
					{
						break;
					}
					cnt++;
				}
				int cnt1 = it -> second - cnt;
				for(int j  = min(r, i + f - 1) + 1; j < min(r, i + f - 1) + 1 + cnt1; j++)
				{
					ans[j] = ans[min(r, i + f - 1)];
				}
				i += cnt1;
			}
		}
	}
}
signed main(){
	cin >> n;
	ans.resize(n);
	set <pair <int, int> > s;
	funct(0, n - 1, s);
	cout << "! ";
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	cout << endl;
	fflush(stdout);
	return 0;
}