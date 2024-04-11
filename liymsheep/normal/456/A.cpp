#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

struct NODE {
	int a, b;
	NODE () {}
	NODE (int a, int b) : a(a), b(b) {}
	bool operator < (const NODE o) const { return a == o.a ? b < o.b : a < o.a ; }
}	;

NODE nn[100005];
int main()
{	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		nn[i] = NODE(x, y);
	}
	sort(nn, nn + n);
	
	int mark = 0;
	for (int i = 1; i < n; i++)
		if (nn[i].a != nn[i - 1].a) {
			mark |= nn[i].b < nn[i - 1].b;
		}
	puts(mark ? "Happy Alex" : "Poor Alex");
	return 0;
}