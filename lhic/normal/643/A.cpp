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

const int MAXN = 5001;
int a[MAXN];
int ans[MAXN];
int cur[MAXN];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	memset(ans, 0, sizeof(ans));
	for (int i = 0; i < n; i++)
	{
		memset(cur, 0, sizeof(cur));
		pair <int, int> mx = mp(0, 0);
		for (int j = i; j < n; j++)
		{
			mx = max(mx, mp(++cur[a[j]], -a[j]));
			ans[-mx.second]++;
		}
	}
	for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	cout << endl;
	return 0;
}