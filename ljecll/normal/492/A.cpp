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

int N;
int no;

int main()
{
//	freopen ("cf492a.in", "r", stdin);
//	freopen ("cf492a.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 1; ; i++)
	{
		int x = (i * i + i)/2;
		no += x;
		if (no > N)
		{
			printf("%d\n", i - 1);
			return 0;
		}
	}
}