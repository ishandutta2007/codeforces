/*
PROG: cf705a
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

using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf705a.in", "r"))
	{	
		freopen ("cf705a.in", "r", stdin);
		freopen ("cf705a.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		if (i !=0)
		{
			cout << "that ";
		}
		cout << "I ";
		if (i % 2 == 0)
		{
			cout << "hate ";
		}
		else
		{
			cout << "love ";
		}
	}
	cout << "it\n";
	return 0;
}