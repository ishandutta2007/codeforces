#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
const int N = 2e5 + 100;
int n;
map<string, vector<int> > id;
string a[N], b[N];
string ans[N];
set<string> st;
map<string, int> ap, ID;
map<int, string> bh;
int v;
vector<int> mp[N];
int To[N], vis[N], turn[N];

int Find(string ch) 
{
	if (ID.count(ch)) return ID[ch];
	int k = (int)ID.size();
	ID[ch] = k;
	bh[k] = ch;
	return k;
}

void insert(int u, int v)
{
	mp[u].push_back(v);
	mp[v].push_back(u);
}

bool dfs(int u) 
{
	vis[u] = 1;
	for (int i = 0; i < mp[u].size(); i ++) 
	{
		int v = mp[u][i], w = To[v];
		if (w < 0 || (!vis[w] && dfs(w))) 
		{
			To[u] = v;
			To[v] = u;
			return true;
		}
	}
	return false;
}

int main() 
{
	cin >> n;
	for (int i = 0; i < n; i ++) 
	{
		cin >> a[i] >> b[i];
		id[a[i].substr(0, 3)].push_back(i);
	}

	bool flag = 1;
	for (auto now : id) 
	{
		vector<int> vc = now.Y;
		if (vc.size() > 1) 
			for (auto i : vc) 
			{
				ans[i] += now.X.substr(0, 2);
				ans[i] += b[i][0];
				if (st.count(ans[i])) {flag = 0; break;}
				st.insert(ans[i]);
			}
	}

	for (auto now : id) 
	{
		vector<int> vc = now.Y;
		if (vc.size() == 1) 
		{
			int i = vc[0];
			string nm1 = now.X;
			string nm2 = now.X.substr(0, 2) + b[i][0];
			turn[i] = 1;
			if (!st.count(nm1)) insert(i, n + Find(nm1));
			if (!st.count(nm2)) insert(i, n + Find(nm2));
		}
	}

	v = n + (int)ID.size();
	int res = 0;
	memset(To, -1, sizeof To);
	for (int i = 0; i < v; i ++) 
		if (To[i] < 0) 
		{
			memset(vis, 0, sizeof vis);
			if (dfs(i)) res ++;
		}

	for (int i = 0; i < n; i ++) 
	{
		if (!turn[i]) continue;
		if (To[i] == -1) 
		{
			flag = 0;
			break;
		}
		ans[i] = bh[To[i] - n];
	}
	for (int i = 0; i < n; i ++) ap[ans[i]] ++;
	for (auto i : ap) if (i.Y > 1) {flag = 0; break;}
	
	if (!flag) cout << "NO";
	else 
	{
		cout << "YES" << endl;
		for (int i = 0; i < n; i ++) 
			cout << ans[i] << endl;
	}

	return 0;
}