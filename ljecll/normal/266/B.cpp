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

int N, T;
string q;

int main()
{
//	freopen ("cf266b.in", "r", stdin);
//	freopen ("cf266b.out", "w", stdout);
	scanf("%d %d", &N, &T);
	cin >> q;
	for (int j = 0; j < T; j++)
	{
		for (int i = N - 2; i >= 0; i--)
		{
			if (q[i] == 'B' && q[i + 1] == 'G')
			{
				swap(q[i], q[i + 1]);
				i--;
			}
		}
	}
	cout << q << endl;
	return 0;
}