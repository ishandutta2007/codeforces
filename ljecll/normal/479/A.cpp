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

int a, b, c;

int main()
{
//	freopen ("cf479a.in", "r", stdin);
//	freopen ("cf479a.out", "w", stdout);
	scanf("%d %d %d", &a, &b, &c);
	printf("%d\n", max(a + b + c, max(a + b * c, max(a * b + c, max(a * b * c, max(a * c + b * c, a * b + a * c))))));
}