#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int n = 0;
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	n = a + b + c + d;
	deque <int> deq;
	if(a)
	{
		deq.push_back(0);
		a--;
	}
	else if(b)
	{
		deq.push_back(1);
		b--;
	}
	else if(c)
	{
		deq.push_back(2);
		c--;
	}
	else if(d)
	{
		deq.push_back(3);
		d--;
	}
	while(true)
	{
		if(a < 0 || b< 0 || c < 0 || d < 0)
		{
			cout << "NO";
			return 0;
		}
		bool fl =false;
		if(a)
		{
			if(deq.front() == 1)
			{
				deq.push_front(0);
				a--;
				fl = true;
			}
			else if(deq.back() == 1)
			{
				deq.push_back(0);
				a--;
				fl = true;
			}
		}
		if(b && !fl)
		{
			if(abs(deq.front() - 1) == 1)
			{
				deq.push_front(1);
				b--;
				fl = true;
			}
			else if(abs(deq.back() - 1) == 1)
			{
				deq.push_back(1);
				b--;
				fl = true;
			}
		}
		if(c && !fl)
		{
			if(abs(deq.front() - 2) == 1)
			{
				deq.push_front(2);
				c--;
				fl = true;
			}
			else if(abs(deq.back() - 2) == 1)
			{
				deq.push_back(2);
				fl = true;
				c--;
			}
		}
		if(d && !fl)
		{
			if(abs(deq.front() - 3) == 1)
			{
				deq.push_front(3);
				d--;
				fl = true;
			}
			else if(abs(deq.back() - 3) == 1)
			{
				deq.push_back(3);
				d--;
				fl = true;
			}
		}
		if(!fl)
		{
			break;
		}
	}
	if(deq.size() == n)
	{
		cout << "YES\n";
		while(!deq.empty())
		{
			cout << deq.front() << " ";
			deq.pop_front();
		}
	}
	else
	{
		cout << "NO";
	}
    return 0;
}