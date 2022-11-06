#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define rep(i, x, y) for(int (i) = (x); (i) <= (y); (i) ++)
#define eps 1e-9
using namespace std;
int main()
{
	int x1, x2, a, b, c = 1;
	cin >> x1 >> x2 >> a >> b;
	if(x2 < x1)
	{
		swap(x1, x2);
		a = -a;
		b = -b;
		swap(a, b);
		c = -1;
	}
	
	if(a > 0 && b > 0)
	{
		if(a + b == 0)cout<<"DRAW\n";
		else
		{
			int v1 = x2 - x1, v2 = a + b;
			if(v1 % v2 == 0) cout << "SECOND\n";
			else if(v1 % v2 >= a && v1 % v2 <= b) cout << "FIRST\n" << (c == 1 ? x1 : x2) + c * (v1 % v2);
			else cout << "DRAW\n";
		}
	}
	else 
	{
		if(x2 - x1 <= b && x2 - x1 >= a) cout << "FIRST\n" << (c == 1 ? x2 : x1);
		else cout << "DRAW\n";
	}
	return 0;
}