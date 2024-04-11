#include <bits/stdc++.h>
#define fst first
using namespace std;
typedef long long lint;
typedef long double llf;
typedef pair<int, int> pi;

int n, m, a[2005];
string s[2005];
set<int> S[2005][26];
set<int> S2[2005];

string t;
pi dp[2005][2005];
bool vis[2005][2005];

pi next_occ(pi x, char t)
{
	int stp = x.second + 1;
	auto it = S[a[x.fst]][t - 'a'].lower_bound(stp);
	if(it != S[a[x.fst]][t - 'a'].end()) return pi(x.fst, *it);
	it = S2[t - 'a'].lower_bound(x.fst + 1);
	if(it == S2[t - 'a'].end()) return pi(m+10, 0);
	x.fst = *it;
	it = S[a[x.fst]][t - 'a'].begin();
	return pi(x.fst, *it);
}

pi f(int x, int y)
{
	if(y == 0) return pi(0, -1);
	if(x == 0) return pi(m+10, 0);
	if(vis[x][y]) return dp[x][y];
	pi ret = f(x-1, y);
	ret = min(ret, next_occ(f(x-1, y-1), t[x-1]));
	vis[x][y] = 1;
	return dp[x][y] = ret;
}

int main(){
	cin >> n;
	for(int i=1; i<=n; i++)
	{
		cin >> s[i];
		for(int j=0; j<s[i].size(); j ++)
			S[i][s[i][j]-'a'].insert(j);
	}
	cin >> m;
	for(int i=0; i<m; i++)
	{
		cin >> a[i];
		for(int j=0; j<26; j++)
			if(S[a[i]][j].size()) S2[j].insert(i);
	}
	cin >> t;
	for(int i=t.size(); i>=0; i --)
		if(f(t.size(), i).fst <= m)
		{
			printf("%d",i);
			return 0;
		}
	return 0;
}