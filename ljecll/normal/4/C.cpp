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
map<string, int> username;

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		username[s]++;
		if (username[s] == 1)
		{
			printf("OK\n");
		}
		else
		{
			cout << s << username[s] - 1 << '\n';
		}
	}
	return 0;
}