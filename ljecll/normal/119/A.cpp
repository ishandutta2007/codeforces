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

int no[2], N;

void move(int a, int b) //person, stones left
{
//	cerr << b << endl;
	int x = __gcd(no[a], b);
	if (x > b)
	{
		printf("%d", a);
		exit(0);
	}
	move(!a, b - x);
}

int main()
{
//	freopen ("cf119a.in", "r", stdin);
//	freopen ("cf119a.out", "w", stdout);
	//simon is 1
	scanf("%d %d %d", &no[1], &no[0], &N);
	move(1, N);
	return 0;
}