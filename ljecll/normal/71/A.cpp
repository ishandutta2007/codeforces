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

void convert(string a)
{
	if (a.length() <= 10)
	{
		printf("%s\n", a.c_str());
		return;
	}
	else
	{
		printf("%c%u%c\n", a[0], a.length() - 2, a[a.length() - 1]);
		return;
	}
}

int main()
{
//	freopen ("cf071a.in", "r", stdin);
//	freopen ("cf071a.out", "w", stdout);
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		convert(s);
	}
	return 0;
}