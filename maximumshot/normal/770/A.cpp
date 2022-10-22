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
bool solve()
{
	int n(0), k(0); cin >> n >> k;
	string t; char cur = 'a';
	for (int i(0); i < n; i++)
	{
		t += cur;
		cur++;
		if (cur>('a' + k - 1)) cur = 'a';
	}

	cout << t << endl;
	return 1;
}
int main()
{
	solve();
//	while (solve());
	return 0;
}