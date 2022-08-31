#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

#define X first
#define Y second

/*
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> rbtree;
rbtree T;
*/

const int MAXN = 300010;

int main()
{
	int T;
	cin >> T;
	string s;
	int ans = 0;
	while (cin >> s)
	{
		int x = 0;
		for (auto c : s)
			if ('A' <= c && c <= 'Z') ++ x;
		ans = max(ans, x);
	}
	cout << ans << endl;
	
	return 0;
}