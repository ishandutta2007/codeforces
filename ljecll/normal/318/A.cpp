/*
PROG: cf318a
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

using namespace std;

long long K, N;

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf318a.in", "r"))
	{	
		freopen ("cf318a.in", "r", stdin);
		freopen ("cf318a.out", "w", stdout);
	}
	cin >> N >> K;
	if (N % 2)
	{
		//N is odd, therefore cutoff is (N + 1)/2
		if (K <= (N + 1)/2)
		{
			cout << K * 2 - 1;
		}
		else
		{
			cout << 2 * K - N  - 1;
		}
	}
	else
	{
		if (K <= (N/2))
		{
			cout << 2 * K - 1;
		}
		else
		{
			cout << 2 * K - N;
		}
	}
	cout << '\n';
	return 0;

}