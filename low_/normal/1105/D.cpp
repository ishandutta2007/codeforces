#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

const pii blocker = {inf, inf};
int n, m, p;
int s[15];
char board[1005][1005];
deque <pair <pii, int> > Q[15], Q2[15];
int ans[15];

bool endGame()
{
	int ret=0;
	for (int i=1; i<=p; i++) ret+=Q[i].size();

	return (ret<=0);
}

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i=0; i<1005; i++) for (int j=0; j<1005; j++) board[i][j]='#';
	cin>>n>>m>>p;
	char cc;
	for (int i=1; i<=p; i++) cin>>s[i];
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++)
	{
		cin>>cc;
		if (cc=='.' || cc=='#') board[i][j]=cc;
		else board[i][j]='#', Q[cc-'0'].push_back({{i, j}, 0}), ans[cc-'0']++;
	}

	int dir[8]={0, 1, 1, 0, 0, -1, -1, 0};
	while (!endGame()) {
		for (int i=1; i<=p; i++) {
			// cerr<<"Player "<<i<<" size: "<<Q[i].size()<<"\n";
			while (!Q[i].empty()) {
				pii t=Q[i].front().XX; 
				int u=Q[i].front().YY;
				// cerr<<"In player "<<i<<": "<<t.XX<<" "<<t.YY<<" "<<u<<"\n";
				Q[i].pop_front();
				if (u==s[i]) {
					Q2[i].push_back({t, 0});
					continue;
				}
				for (int d=0; d<8; d+=2) {
					int x=t.XX+dir[d], y=t.YY+dir[d+1];
					if (board[x][y]=='#') continue;
					board[x][y]='#';
					Q[i].push_back({{x, y}, u+1});
					ans[i]++;
				}
			}
			Q[i]=Q2[i];
			Q2[i].clear();
		}
	}

	for (int i=1; i<=p; i++) cout<<ans[i]<<' ';
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/