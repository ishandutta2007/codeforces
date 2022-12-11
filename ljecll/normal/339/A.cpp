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

string s;
priority_queue<char, vector<char>, greater<char> > pq;

int main()
{
//	freopen ("cf339a.in", "r", stdin);
//	freopen ("cf339a.out", "w", stdout);
	cin >> s;
	for (int i = 0; i < s.length(); i += 2)
	{
		pq.push(s[i]);
	}
	cout << pq.top();
	pq.pop();
	while(!pq.empty())
	{
		cout << '+' << pq.top();
		pq.pop();
	}
	return 0;
}