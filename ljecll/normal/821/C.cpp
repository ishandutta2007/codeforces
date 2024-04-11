/*
PROG: cf821c
LANG: C++
*/
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define MP make_pair
#define PB push_back

#define SINF 10001
#define INF 1000000007
#define MOD INF
#define LLINF 1000000000000000861ll
#define CO 1000861
#define EPS 0.000000000000001
#define PI 3.141592653589793

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int N;
stack<int> q;
priority_queue<int, vector<int>, greater<int> > pq;
int id;
int ans;

int32_t main()
{
	ios_base::sync_with_stdio(false);
	if (fopen("cf821c.in", "r"))
	{	
		freopen ("cf821c.in", "r", stdin);
		freopen ("cf821c.out", "w", stdout);
	}
	cin >> N;
	for (int i = 0; i < 2 * N; i++)
	{
		string s;
		cin >> s;
		if (s[0] == 'a')
		{
			int id;
			cin >> id;
			q.push(id);
			continue;
		}
		id++;
		//remove
		if (q.empty())
		{
			pq.pop();
		}
		else
		{
			if (q.top() == id)
			{
				q.pop();
			}
			else
			{
				while(!q.empty())
				{
					int u = q.top();
					pq.push(u);
					q.pop();
				}
				pq.pop();
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}