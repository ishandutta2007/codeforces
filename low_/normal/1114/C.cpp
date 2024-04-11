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

int n, b;
vector <pii> FactB={};
vector <pii> FactN={};

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>b;
	
	int b1=b;
	for (int i=2; i*i<=b; i++) if (b1%i==0)
	{
		int tmp=0;
		while (b1%i==0)
		{
			tmp++;
			b1/=i;
		}
		FactB.push_back({i, tmp});
	}
	
	if (b1>1) FactB.push_back({b1, 1});
	
	FactN=FactB;
	for (int i=0; i<FactN.size(); i++) 
	{
		FactN[i].YY=0;
		int n1=n;
		while (n1>0)
		{
			n1/=FactN[i].XX;
			FactN[i].YY+=n1;
		}
	}
	int ans=inf;
	for (int i=0; i<FactN.size(); i++)
	{
		ans=min(ans, FactN[i].YY/FactB[i].YY);
	}
	cout<<ans;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/