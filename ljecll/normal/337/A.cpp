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

#define MAXM 55
#define INFTY 10000001

using namespace std;

int N, M;
int diff[MAXM];
int ans = INFTY;

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> diff[i];
	}
	sort(diff, diff + M);
	for (int i = N - 1; i < M; i++)
	{
		int a = diff[i] - diff[i - N + 1];
//		cerr << a << endl;
		if (a < ans)
		{
			ans = a;
//			cerr << diff[i] << ' ' << diff[i - N - 1];
		}
	}
	printf("%d\n", ans);
	return 0;

}