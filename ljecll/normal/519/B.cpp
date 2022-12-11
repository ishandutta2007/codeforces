/*
PROG: cf519b
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

using namespace std;

int N;
map<int, int> s1;
map<int, int> s2;
map<int, int> s3;

int main()
{
	if (fopen("cf519b.in", "r"))
	{	
		freopen ("cf519b.in", "r", stdin);
		freopen ("cf519b.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		s1[a]++;
	}
	for (int i = 1; i < N; i++)
	{
		int a;
		cin >> a;
		s2[a]++;
	}
	for (map<int, int>::iterator it = s1.begin(); it != s1.end(); it++)
	{
		if (s2[it -> first] != s1[it -> first])
		{
			cout << it -> first << '\n';
			break;
		}
	}
	for (int i = 2; i < N; i++)
	{
		int a;
		cin >> a;
		s3[a]++;
	}
	for (map<int, int>::iterator it = s2.begin(); it != s2.end(); it++)
	{
		if (s3[it -> first] != s2[it -> first])
		{
			cout << it -> first << '\n';
			break;
		}
	}
}