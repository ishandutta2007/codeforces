/*
PROG: cf734b
LANG: C++
debug my code
*/
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

#define INF 1000000001
#define LLINF 1000000000000000001ll
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;

ll no[4];
ll a, b;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf734b.in", "r"))
	{	
		freopen ("cf734b.in", "r", stdin);
		freopen ("cf734b.out", "w", stdout);
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> no[i];
	}
	//make 01 or 023
	b = min(no[0], min(no[2], no[3]));
	a = min(no[1], no[0] - b);
	cout << 32ll * a + 256ll*b << '\n';
	return 0;
}