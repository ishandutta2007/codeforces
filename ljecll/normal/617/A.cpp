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

using namespace std;

int N, ans;

int main()
{
	if (fopen("cf617c.in", "r"))
	{	
		freopen ("cf617c.in", "r", stdin);
		freopen ("cf617c.out", "w", stdout);
	}
	cin >> N;
	ans = N/5;
	if (N % 5)
	{
		ans++;
	}
	cout << ans << '\n';
	return 0;
}