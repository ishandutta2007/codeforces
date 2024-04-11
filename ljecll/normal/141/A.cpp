#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <functional>
#include <ctime>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <complex>
#include <iomanip>

using namespace std;

string a, b, c;
int no[262];

int main()
{
    ios_base::sync_with_stdio(false);
    if (fopen("cf141a.in", "r"))
    {
        freopen ("cf141a.in", "r", stdin);
	    freopen ("cf141a.out", "w", stdout);
    }
	cin >> a >> b >> c;
	for (int i = 0; i < a.length(); i++)
	{
		no[a[i]]++;
	}
	for (int i = 0; i < b.length(); i++)
	{
		no[b[i]]++;
	}
	for (int i = 0; i < c.length(); i++)
	{
		no[c[i]]--;
	}
	for (int i = 0; i <= 256; i++)
	{
		if (no[i])
		{
    		cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	return 0;
}