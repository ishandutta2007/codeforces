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
#include <memory.h>
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
const int MAXN = 200001;
set <pair <int,  int> > st;

int t[MAXN];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	int n, q, k;
	cin >> n >> k >> q;
	for (int i = 1; i <= n; i++) cin >> t[i];
	for (int i = 0; i < q; i++)
	{
		int tp, x;
		cin >> tp >> x;
		if (tp == 1)
		{
			st.insert(make_pair(t[x], x));
			if (st.size() > k) st.erase(*st.begin());
		}
		else
		{
			if (st.find(make_pair(t[x], x)) != st.end()) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}