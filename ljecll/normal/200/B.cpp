/*
PROG: cf200b
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

#define MAXN 101

using namespace std;

int N;
int q;
double ans;

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf200b.in", "r"))
	{	
		freopen ("cf200b.in", "r", stdin);
		freopen ("cf200b.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> q;
		ans += (double) q;
	}
	cout << fixed << setprecision(100) << ans/(double) N << '\n';
}