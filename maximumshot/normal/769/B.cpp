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
using namespace std;
typedef signed long long int lli;
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
bool cmp(pair< int, int > d1, pair< int, int > d2)
{
	return d1.first>d2.first;
}
vector< bool > us;
vector<pair< int, int > > a;
vector<pair< int, int > > ans;
void go(int x)
{
	us[x] = 1;
	int k = a[x].first;
	for (int i(0); i < sz(a); i++)
	{
		if (!us[i] && k)
		{
			ans.push_back(make_pair(x, i));
			go(i);   k--;
		}
	}
}
bool solve()
{
	int n; cin >> n;
	a.resize(n); us.resize(n);
	for (int i(0), t(0); i < n; i++)
	{
		cin >> t; a[i] = make_pair(t, i);
	}
	sort(ALL(a), cmp);
	for (int i(0); i < n; i++)
	{
		if (!a[i].second) go(i);
	}
	for (int i(0); i < n; i++) if (!us[i]) { cout << "-1" << endl; return 1; }
	cout << sz(ans) << endl;
	for (int i(0); i < sz(ans); i++)
	{
		cout << a[ans[i].first].second + 1 << " " << a[ans[i].second].second + 1 << endl;
	}
	return 1;
}
int main()
{
	solve();
//	while (solve());
	return 0;
}