#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair <int, int> BONG;
typedef unsigned int ui;
const int inf = 1e9+9;


int n,m,a,b;
string s;


int main()
{
	cin >>s;
	int dl = s.size();
	for (int i=0; i<dl; ++i)
	{
		int x = s[i]-'0';
		x = min(x, 9-x);
		if (i == 0 && x == 0) x = 9;
		char zn = x + '0';
		cout << zn;
	}
}