#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

const int MAXN = 100001;
bool w[MAXN];
int d[MAXN];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) cin >> d[i];
	int cur = 0;
	for (int iter = 0; iter <= n; iter++)
	{
		if (s[cur] == '>') cur += d[cur];
		else cur -= d[cur];
		if ((cur < 0) || (cur >= n))
		{
			cout << "FINITE" << endl;
			return 0;
		}
	}
	cout << "INFINITE" << endl;
	return 0;
}