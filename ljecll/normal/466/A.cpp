/*
PROG: cf466a
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

int N, M, A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf466a.in", "r"))
	{	
		freopen ("cf466a.in", "r", stdin);
		freopen ("cf466a.out", "w", stdout);
	}
	cin >> N >> M >> A >> B;
	if (A * M <= B)
	{
		cout << N * A << '\n';
		return 0;
	}
	int qfull, qrem;

		qfull = N/M;
		qrem = N % M;
	cout << qfull * B + min(B, qrem * A) << '\n';
	return 0;
}