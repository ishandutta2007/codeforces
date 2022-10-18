#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>

#include <unordered_map>

using namespace std;

#ifdef LOCAL
#define debug_flag 1
#else
#define debug_flag 0
#endif

template <class T1, class T2 >
std::ostream& operator << (std::ostream& os, const pair<T1, T2> &p)
{
	os << "[" << p.first << ", " << p.second << "]";
	return os;
}

template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
	os << "[";
	bool first = true;
	for (typename std::vector<T>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		if (!first)
			os << ", ";
		first = false;
		os << *it;
	}
	os << "]";
	return os;
}

template <class T >
std::ostream& operator << (std::ostream& os, const std::vector<vector<T>>& v)
{

	os << "[" << endl;
	bool first = true;
	for (typename std::vector<vector<T>>::const_iterator it = v.begin(); it != v.end(); ++it)
	{
		os << *it << endl;
	}
	os << "]" << endl;
	return os;
}

typedef long long int int64;

const int N = 105;

int n, m;
string s_list[N];
set<char> c_set[N];
bool need_del[N];

void fail()
{
	cout << "No" << endl;
	exit(0);
}

bool match(string s, string pat)
{
	if (s.length() != pat.length())
		return false;

	for (int i = 0; i < (int)s.length(); i++)
	{
		if (pat[i] == '?')
			continue;
		if (pat[i] != s[i])
			return false;
	}

	return true;
}

void solve()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> s_list[i];
	
	int len = -1;

	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		a--;
		need_del[a] = true;

		if (len == -1)
			len = (int)s_list[a].length();

		if (len != (int)s_list[a].length())
			fail();

		for (int j = 0; j < (int)s_list[a].length(); j++)
		{
			c_set[j].insert(s_list[a][j]);
		}
	}

	string pat;
	for (int i = 0; i < len; i++)
	{
		if (c_set[i].size() == 1)
			pat.push_back(*c_set[i].begin());
		else
			pat.push_back('?');
	}

	for (int i = 0; i < n; i++)
	{
		if (!need_del[i] && match(s_list[i], pat))
			fail();
	}

	cout << "Yes" << endl;
	cout << pat << endl;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif

	solve();

	return 0;
}