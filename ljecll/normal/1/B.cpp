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
#define INFTY 1 << 29

using namespace std;

int N;
string s;

void convert1(string a, int b)
{
	//R23C55

	//b provides location of the 'C'
	int colno;
	string ans;
	for (int i = b + 1; i < a.length(); i++)
	{
		ans += a[i];
	}
	colno = stoi(ans);
	//we only need to convert the col
	ans.clear();
	vector<char> v;
	while(colno > 0)
	{
		colno--;
		v.push_back((colno % 26) + 'A');
		colno /= 26;
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i];
	}
	//cout <<stuff;
	for (int i = 1; i < b; i++)
	{
		cout << a[i];
	}
	cout << '\n';
	return;
}
void convert2(string a)
{
	//BC23
	int ans = 0;
	int b = INFTY;
	cout << 'R';
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i]))
		{
			cout << s[i];
			b = min(b, i);
		}
	}
	for (int i = 0; i < b; i++)
	{
		ans *= 26;
		ans += (s[i] - 'A' + 1);
	}
	cout << 'C';
	//now we need to convert the column
	cout << ans << '\n';
}
void convert(string a)
{
	for (int i = 1; i < a.length(); i++)
	{
		if (a[i] == 'C' && isdigit(a[i - 1]))
		{
			convert1(a, i);
			return;
		}
	}
	convert2(a);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf1b.in", "r"))
	{	
		freopen ("cf1b.in", "r", stdin);
		freopen ("cf1b.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		convert(s);
	}
}