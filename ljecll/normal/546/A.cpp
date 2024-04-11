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

int total;
int K, N, W; //first cost, soldier money, # bananas wanted

int main()
{
//	freopen ("cf546a.in", "r", stdin);
//	freopen ("cf546a.out", "w", stdout);
	scanf("%d %d %d", &K, &N, &W);
	total = ((W * W + W)* K)/2;
	if (total < N)
	{
		printf("0\n");
		return 0;
	}
	else
	{
		printf("%d\n", total - N);
	}
	return 0;
}