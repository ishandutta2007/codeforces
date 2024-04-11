/*
PROG: cf489b
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

#define MAXN 101

using namespace std;

int N, M;
int boy[MAXN], girl[MAXN];
int ite = 0;
int ans;

int main()
{
	if (fopen("cf489b.in", "r"))
	{	
		freopen ("cf489b.in", "r", stdin);
		freopen ("cf489b.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> boy[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> girl[i];
	}
	sort(boy, boy + N);
	sort(girl, girl + M);
	for (int i = 0; i < N; i++)
	{
		while (ite < M && girl[ite] <= boy[i] + 1)
		{
			if (girl[ite] == boy[i] - 1 || girl[ite] == boy[i] || girl[ite] == boy[i] + 1)
			{
				ans++;
				ite++;
				break;
			}
			ite++;
		}
	}
	cout << ans << '\n';
}