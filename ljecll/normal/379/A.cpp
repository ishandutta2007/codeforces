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

int M, N;
int ans;
int burnt;

int main()
{
//	freopen ("cf379a.in", "r", stdin);
//	freopen ("cf379a.out", "w", stdout);
	scanf("%d %d", &N, &M);
	ans += N;
	burnt += N;
	//while its not equal to zero
	while(burnt >= M)
	{
		ans += (burnt/M);
		burnt -= ((burnt/M) * (M - 1));
	}
	//N new candles, can make M burnt into a new one
	printf("%d\n", ans);
	return 0;
}