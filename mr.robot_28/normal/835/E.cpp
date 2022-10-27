#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n, x, y;
    cin >> n >> x >> y;
    int t = log2(n - 1);
    int mask = 0;
    int bit = 0;
    for(int i = 0; i <= t; i++)
    {
    	vector <int> ask;
    	for(int j = 0; j < n; j++)
    	{
    		if((j & (1 << i)) != 0)
    		{
    			ask.push_back(j);
			}
		}
		cout << "? " << ask.size() << " ";
		for(int j = 0; j < ask.size(); j++)
		{
			cout << ask[j] + 1 << " ";
		}
		cout << endl;
		fflush(stdout);
		int a;
		cin >> a;
		bool flag = false;
		if(a == (x ^ y) || a == y)
		{
			bit = i;
			mask |= (1 << i);
			flag = true;
		}
	}
	vector <int> p1, p2;
	for(int i = 0; i < n; i++)
	{
		if((i & (1 << bit)))
		{
			p1.push_back(i);
		}
		else
		{
			p2.push_back(i);
		}
	}
	if(p1.size() > p2.size())
	{
		swap(p1, p2);
	}
	int l = 0, r = p1.size() - 1;
	while(r > l)
	{
		int midd = (r + l) / 2; 
		cout << "? ";
		cout << midd + 1 << " ";
		for(int i = 0; i <= midd; i++)
		{
			cout << p1[i] + 1 << " ";
		}
		cout << endl;
		fflush(stdout);
		int a;
		cin >> a;
		if(a == y || a == (x ^ y))
		{
			r = midd;
		}
		else
		{
			l = midd + 1;
		}
	}
	int a = p1[l] + 1;
	int b = (p1[l] ^ mask) + 1;
	if(a > b)
	{
		swap(a, b);
	}
	cout << "! " << a<< " " << b << endl;
	fflush(stdout);
    return 0;
}