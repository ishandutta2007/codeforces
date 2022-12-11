/*
PROG: cf500a
LANG: C++
debug my code
*/
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
#include <iomanip>

#define MAXN 30003
using namespace std;

int N, T;
int arr[MAXN];
int val[MAXN];
bool seen[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf500a.in", "r"))
	{	
		freopen ("cf500a.in", "r", stdin);
		freopen ("cf500a.out", "w", stdout);
	}
	cin >> N >> T;
	T--;
	for (int i = 0; i < N - 1; i++)
	{
		cin >> val[i];
	}
	int loc = 0;
	while(!seen[loc])
	{
		if (loc == T)
		{
			cout << "YES\n";
			return 0;
		}
		if (loc == N - 1)
		{
			break;
		}
		seen[loc] = true;
		loc += val[loc];
		cerr << loc << endl;
	}
	cout << "NO\n";
}