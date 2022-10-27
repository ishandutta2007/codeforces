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
using namespace std;
#define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define X first
#define Y second

pair <int, pii> dp[5005][505];
int d, s;

void bfs()
{
	for (int i=0; i<=s; i++) for (int j=0; j<d; j++) dp[i][j]={-1, {-1, -1}};
//	cerr<<dp[s][0].X<<"\n";
	dp[0][0].X=0;
	deque <pii> Q={{0, 0}};
	while (!Q.empty())
	{
		pii temp=Q.front();
		Q.pop_front();
		if (temp.X==s && temp.Y==0) return;
//		cout<<temp.X<<" "<<temp.Y<<"\n";
//		if (temp.first>s) continue;
		
		for (int i=0; i<=9; i++) if (dp[temp.X+i][(temp.Y*10+i)%d].X==-1)
		{
			dp[temp.X+i][(temp.Y*10+i)%d]={i, temp};
			Q.push_back({temp.X+i, (temp.Y*10+i)%d});
		}
	}
//	cerr<<dp[s][0].X<<"\n";
}

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>d>>s;
	
	bfs();
	if (dp[s][0].X==-1) cout<<"-1";
	else
	{
		string ans="";
		int i=s, j=0, ip, jp;
		while (i>0)
		{
			ans.push_back(dp[i][j].X+'0');
			ip=dp[i][j].Y.X;
			jp=dp[i][j].Y.Y;
			i=ip, j=jp;
		}
		reverse(ans.begin(), ans.end());
		cout<<ans;
	}
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/