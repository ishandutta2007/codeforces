#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <list>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <ctime >
#include <sstream>
using namespace std;
typedef unsigned long long int lli;
typedef vector<int> vi;
#define FOR(i, p, n) for(int i(p); i < n; i++)
#define FORR(i,p) for( i(p); i>=0; i--)
#define ALL(a) (a.begin()),(a.end())
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(1.0*(x))
#define pow(x,n) pow(1.0*(x),n)
#define FORI(n) for(int i=0;i<n;i++)
#define sz(V) (int)V.size()
#define pb push_back
#define UN(x) (x).resize(unique(ALL((x))) - (x).begin());
#define mp make_pair
const int INF = 1000000000;
vector< vector< char > > gr;
void add(int x, int &up, bool f)
{
	int mid = gr.size() / 2;
	int lim = f ? up - 2 : up + 2;
	for (int i(0); i <= lim / 2; i++)
	{
		if (i == lim / 2) {
			gr[mid + i][x] = '+'; gr[mid - i][x] = '+';
			int t = f ? x + 1 : x - 1;
			gr[mid + i][t] = '-';  gr[mid - i][t] = '-';
			break;
		}
		gr[mid + i][x] = '|';
		gr[mid - i][x] = '|';
	}
	up = f ? up - 2 : up + 2;
}
bool solve(string s)
{
	int deep(0);
	for (int i(0), cur(0); i < s.size(); i++)
	{
		if (s[i] == '[')  cur++; else cur--;
		deep = max(cur, deep);
	}
	vector< char > wt;
	gr.assign(3 + (deep - 1) * 2, wt);
	for (int i(0); i < gr.size(); i++) gr[i].assign(300,' ');
	int lastopen(0), lastclose(0);
	lastopen = 3 + deep * 2;
	lastclose = lastopen - 2;
	int l(0);
	for (int i(0); i < s.size(); i++, l++)
	{
		if (s[i] == ']') if (s[i - 1] == '[') l += 3;
		if (s[i] == '[') { add(l, lastopen, 1); lastclose -= 2; }
		else { add(l, lastclose, 0); lastopen += 2; }
	}
	for (int i(0); i < gr.size(); i++)
	{
		for (int j(0); j <l; j++)
		{
			cout << gr[i][j];
		}
		cout << endl;
	}
	return 1;
}

int main()
{
	int n; string s;
	cin >> n >> s;
	solve(s);
//	system("pause");
	return 0;
}