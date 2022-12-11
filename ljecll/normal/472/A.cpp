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
#define MAXN 1000010

using namespace std;

bool prime[MAXN];
int N;

void genprime(int a)
{
	prime[a] = true;
	//we know that 0 and 1 are not prime but we dont want them to be marked composite
	for (int i = 2; i * i <= a; i++)
	{
		if (! (a % i))
		{
			prime[a] = false;
			return;
		}
	}
}

int main()
{
//	freopen ("cf472a.in", "r", stdin);
//	freopen ("cf472a.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i <= N; i++)
	{
		genprime(i);
	}
	for (int i = 0; i <= N / 2; i++)
	{
		if (!prime[i] && !prime[N - i])
		{
			printf("%d %d\n", i, N - i);
			return 0;
		}
	}
}