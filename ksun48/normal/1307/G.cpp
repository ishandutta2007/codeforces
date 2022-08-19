#include <bits/stdc++.h>
using namespace std;

const int N = 55, M = 2600 << 1;

int n, m, p, s, t;

int top, head[N], to[M], nxt[M], c[M], l[M];

void
addedge (int u, int v, int cap, int len)
{
	to[top] = v, nxt[top] = head[u], c[top] = cap, l[top] = len, head[u] =
		top++;
}

vector < pair < int, int >>paths;

int dis[N], fa[N];

bool inque[N];

const int INF = 1000000000;

bool
go (int source, int target)
{
	for (int i = 0; i < n; ++i)
		{
			dis[i] = INF;
		}
	dis[source] = 0;
	inque[source] = true;
	queue < int >q;
	q.push (source);
	while (q.size ())
		{
			int u = q.front ();
			inque[u] = false;
			q.pop ();
			for (int i = head[u]; ~i; i = nxt[i])
	{
		if (c[i])
			{
				int v = to[i], nd = dis[u] + l[i];
				if (dis[v] > nd)
		{
			dis[v] = nd;
			fa[v] = i;
			if (!inque[v])
				{
					inque[v] = true;
					q.push (v);
				}
		}
			}
	}
		}
	if (dis[target] == INF)
		{
			return false;
		}
	int f = INF;
	int u = target;
	while (u != source)
		{
			int e = fa[u];
			f = min (f, c[e]);
			u = to[e ^ 1];
		}
	paths.push_back (make_pair (f, dis[target]));
	u = target;
	while (u != source)
		{
			int e = fa[u];
			c[e] -= f, c[e ^ 1] += f;
			u = to[e ^ 1];
		}
	return true;
}

int main () {
	cin >> n >> m;
	s = 0;
	t = n-1;
	top = 0;
	memset (head, -1, sizeof (head));
	for (int i = 0; i < m; ++i) {
		int u, v, d;
		cin >> u >> v >> d;
		u--; v--;
		addedge (u, v, 1, d);
		addedge (v, u, 0, -d);
	}
	while (go (s, t)) {
		continue;
	}
	int q;
	cin >> q;
	vector<int> amt(q);

	vector<pair<int,int> > sorted_amt;
	for(int i = 0; i < q; i++){
		cin >> amt[i];
		sorted_amt.push_back({amt[i], i});
	}
	sort(sorted_amt.begin(), sorted_amt.end());
	vector<double> answers(q);
	int cur = 0;
	int csum = 0, fsum = 0;
	for (int i = 0; i < (int) paths.size (); ++i) {
		csum += paths[i].first * paths[i].second;
		fsum += paths[i].first;
		while(cur < q && (i + 1 == paths.size() || ((double) (sorted_amt[cur].first + csum) / fsum) < paths[i + 1].second)) {
			answers[sorted_amt[cur].second] = (double) (sorted_amt[cur].first + csum) / fsum;
			cur++;
		}
	}
	cout << fixed << setprecision(11);
	for(double d : answers){
		cout << d << '\n';
	}
	return 0;
}