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

string s;

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	for (int rw=1; rw<=5; rw++)
	{
		int q=s.size()/rw, r=s.size()%rw;
		if (q+(r>0)>20) continue;
		q+=(r>0);
		int ptr=0;
		cout<<rw<<" "<<q<<"\n";
		for (int i=0; i<rw; i++)
		{
			for (int j=0; j<q; j++)
			{
				if (r>0 && i>=r && j==1) cout<<"*";
				else
				{
					cout<<s[ptr];
					ptr++;
				}
			}
			cout<<"\n";
		}
		return 0;
	}
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/