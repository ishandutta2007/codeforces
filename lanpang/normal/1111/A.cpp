#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n;
char a[1010] , b[1010];
set<char> s;

int main()
{
	int i , j;
	cin >> a;
	cin >> b;
	n = strlen(a);
	if (strlen(b) != n)
	{
		cout << "No\n";
		return 0;
	}
	s.insert('a');
	s.insert('e');
	s.insert('i');
	s.insert('o');
	s.insert('u');
	for (i = 0 ; i < n ; i++)
	{
		if (s.count(a[i]) != s.count(b[i]))
		{
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}