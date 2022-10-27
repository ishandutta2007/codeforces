#include<bits/stdc++.h>
using namespace std;
bool check(int x, int x1, int y, int y1)
{
	if(x > x1 || y > y1)
	{
		return 0;
	}
	cout << "? " << x  << " " << y << " " << x1 << " " << y1 << endl;
	int A;
	cin >> A;
	if(A == 1)
	{
		return 1;
	}
	return 0;
}
signed main(){
	int n;
	cin >> n;
	int lx = 1, rx = n + 1;
	while(rx - lx > 1)
	{
		int midd = (rx + lx) / 2;
		cout << "? " << midd << " " << 1 << " " << n << " " << n << endl;
		int x;
		cin >> x;
		if(x >= 1)
		{
			lx = midd;
		}
		else
		{
			rx = midd;
		}
	}
	int l1x = 1, r1x = n + 1;
	while(r1x - l1x > 1)
	{
		int midd = (r1x + l1x) / 2;
		cout << "? " << midd << " " << 1 << " " << n << " " << n << endl;
		int x;
		cin >> x;
		if(x > 1)
		{
			l1x = midd;
		}
		else
		{
			r1x = midd;
		}
	}
	int l2x = 0, r2x = n;
	while(r2x - l2x > 1)
	{
		int midd = (r2x + l2x) / 2;
		cout << "? " << 1 << " " << 1 << " " << midd << " " << n << endl;
		int x;
		cin >> x;
		if(x > 1)
		{
			r2x = midd;
		}
		else
		{
			l2x = midd;
		}
	}
	l2x = r2x;
	int l3x = 0, r3x = n;
	while(r3x - l3x > 1)
	{
		int midd = (r3x + l3x) / 2;
		cout << "? " << 1 << " " << 1 << " " << midd << " " << n << endl;
		int x;
		cin >> x;
		if(x < 1)
		{
			l3x = midd;
		}
		else
		{
			r3x = midd;
		}
	}
	l3x++;
	int ly = 1, ry = n + 1;
	while(ry - ly > 1)
	{
		int midd = (ry + ly) / 2;
		cout << "? " << 1 << " " << midd << " " << n << " " << n << endl;
		int x;
		cin >> x;
		if(x >= 1)
		{
			ly = midd;
		}
		else
		{
			ry = midd;
		}
	}
	int l1y = 1, r1y = n + 1;
	while(r1y - l1y > 1)
	{
		int midd = (r1y + l1y) / 2;
		cout << "? " << 1 << " " << midd << " " << n << " " << n << endl;
		int x;
		cin >> x;
		if(x > 1)
		{
			l1y = midd;
		}
		else
		{
			r1y = midd;
		}
	}
	int l2y = 0, r2y = n;
	while(r2y - l2y > 1)
	{
		int midd = (r2y + l2y) / 2;
		cout << "? " << 1 << " " << 1 << " " << n << " " << midd << endl;
		int x;
		cin >> x;
		if(x > 1)
		{
			r2y = midd;
		}
		else
		{
			l2y = midd;
		}
	}
	l2y = r2y;
	int l3y = 0, r3y = n;
	while(r3y - l3y > 1)
	{
		int midd = (r3y + l3y) / 2;
		cout << "? " << 1 << " " << 1 << " " << n << " " << midd << endl;
		int x;
		cin >> x;
		if(x < 1)
		{
			l3y = midd;
		}
		else
		{
			r3y = midd;
		}
	}
	l3y++;
	int x;
	pair <int, int> x1, x2;
	pair <int, int> y1, y2;
	x1 = x2 = y1 = y2 = {-1, -1};
	if(max(lx, l1x) > min(l2x, l3x))
	{
		x1 = {lx, l2x};
		x2 = {l1x, l3x};
	}
	if(max(ly, l1y) > min(l2y, l3y))
	{
		y1 = {ly, l2y};
		y2 = {l1y, l3y};
	}
	if(y1.first == -1)
	{
		if(check(x1.first, x1.second, ly, l2y) && check(x2.first, x2.second, l1y, l3y))
		{
			y1 = {ly, l2y};
			y2 = {l1y, l3y};
		}
		else if(check(x1.first, x1.second, l1y, l2y) && check(x2.first, x2.second, ly, l3y))
		{
			y1 = {l1y, l2y};
			y2 = {ly, l3y};
		}
		else if(check(x1.first, x1.second, ly, l3y) && check(x2.first, x2.second, l1y, l2y))
		{
			y1 = {ly, l3y};
			y2 = {l1y, l2y};
		}
		else if(check(x1.first, x1.second, l1y, l3y))
		{
			y1 = {l1y, l3y};
			y2 = {ly, l2y};
		}
	}
	else if(x1.first == -1)
	{
		if(check(lx, l3x,  y1.first, y1.second) && check(l1x, l2x, y2.first, y2.second))
		{
			x1 = {lx, l3x};
			x2 ={l1x, l2x};
		}
		else if(check(l1x, l3x, y1.first, y1.second) && check(lx, l2x, y2.first, y2.second))
		{
			x1 = {l1x, l3x};
			x2 = {lx, l2x};
		}
		else if(check(l1x, l2x, y1.first, y1.second) && check(lx, l3x, y2.first, y2.second))
		{
			x1 = {l1x, l2x};
			x2 = {lx, l3x};
		}
		else
		{
			x1 = {lx, l2x};
			x2 = {l1x, l3x};
		}
	}
	else if(!check(x1.first, x1.second, y1.first, y1.second))
	{
		swap(x1, x2);
	}
	cout << "! ";
	cout << x1.first << " " << y1.first << " " << x1.second << " " << y1.second << " ";
	cout << x2.first << " " << y2.first << " " << x2.second << " " << y2.second << endl; 
	return 0;
}