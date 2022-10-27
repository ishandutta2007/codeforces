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

int n; string S;
deque <int> D[3]={{}, {}, {}};
pii P[6]={{2, 0}, {1, 0}, {2, 1}, {0, 2}, {1, 2}, {0, 1}};

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>S;
	for (int i=0; i<n; i++) D[S[i]-'0'].push_back(i);
	
	for (int i=0; i<n*6; i++)
	{
		int j=i/n;
		if (D[P[j].XX].size()==n/3 || D[P[j].YY].size()==n/3) continue;
		if (D[P[j].XX].size()<n/3 && D[P[j].YY].size()<n/3) continue;
		if (D[P[j].XX].size()>n/3 && D[P[j].YY].size()>n/3) continue;
		if (D[P[j].XX].size()<D[P[j].YY].size()) continue;
		if (P[j].XX<P[j].YY)
		{
			D[P[j].YY].push_back(D[P[j].XX].back());
			D[P[j].XX].pop_back();
		}
		else
		{
			D[P[j].YY].push_front(D[P[j].XX].front());
			D[P[j].XX].pop_front();
		}
	}
	for (int i=0; i<3; i++) for (int j:D[i]) S[j]='0'+i;
	cout<<S;
	
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/