#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int z[11];
int get(int i)
{
	int res = (1 << 11) - 1;
	for(int j = 0; j < 11; j++)
	{
		if(i == z[j])
		{
			if(z[j] == i && (res & (1 << j)))
		{
			res = res ^ (1 << j);
		}
			continue;
		}
		cout << "? " << i << " " << z[j] << endl;
		fflush(stdout);
		int a;
		cin >> a;
		if(z[j] == i && (res & (1 << j)))
		{
			res = res ^ (1 << j);
		}
		if(z[j] != i)
		{
			res = res & a;
		}
	}
	return res;
}
signed main()
{
	int n;
	cin >> n;
	int ind = 1;
	for(int i = 0; i < 11; i++)
	{
		z[i] = -1;
	}
	while(count(z, z + 11, -1))
	{
        int i=uniform_int_distribution<int>(1,n)(rng),j=uniform_int_distribution<int>(1,n)(rng);
        if(i == j)
        {
        	continue;
		}
		cout << "? " << i << " " << j << endl;
		fflush(stdout);
		int a;
		cin >> a;
		for(int t = 0; t < 11; t++)
		{
			if(!(a & (1 << t)))
			{
				z[t] = i;
			}
		}
	}
	int idx = 1, a = get(1);
	for(int i = 2; i <= n; i++)
	{
		cout << "? " << idx << " " << i << endl;
		fflush(stdout);
		int res;
		cin >> res;
		if(res == a)
		{
			idx = i;
			a = get(i);
		}
	}
	vector <int> p(n + 1);
	p[idx] = 0;
	for(int i = 1; i <= n; i++)
	{
		if(i != idx)
		{
			cout << "? " << i << " " << idx << endl;
			fflush(stdout);
			cin >> p[i];
		}
	}
	cout << "! ";
	for(int i = 1; i <= n; i++)
	{
		cout << p[i] << " ";
	}
    return 0;
}