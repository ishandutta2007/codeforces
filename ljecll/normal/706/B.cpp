/*
PROG: cf706b
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

#define MAXN 1000001

using namespace std;

int N, Q;
int arr[MAXN];
int val[MAXN];

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf706b.in", "r"))
	{	
		freopen ("cf706b.in", "r", stdin);
		freopen ("cf706b.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	cin >> Q;
	for (int i = 0; i < Q; i++)
	{
		int x;
		cin >> x;
		if (x < arr[0])
		{
			cout << 0 << endl;
		}
		else
		{
			int q = upper_bound(arr, arr + N, x) - arr;
			cout << q << '\n';
		}
	}
	return 0;
}