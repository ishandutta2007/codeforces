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

int N;
int no[3];

int main()
{
    if (fopen("cf69.in", "r"))
    {
	    freopen ("cf69a.in", "r", stdin);
	    freopen ("cf69a.out", "w", stdout);
    }
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
	    cin >> a >> b >> c;
		no[0] += a;
		no[1] += b;
		no[2] += c;
	}
	if (no[0] || no[1] || no[2])
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
	}
	return 0;
}