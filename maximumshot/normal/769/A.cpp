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
bool solve()
{
	int n; cin >> n; int mn(INF), mx(0);
	for (int i(0); i < n; i++)
	{
		int t; cin >> t;  mn = min(mn, t); mx = max(mx, t);
	}
	cout << (mx + mn) / 2;
	return 1;
}
int main()
{
	solve();
	//while (solve());
	return 0;
}