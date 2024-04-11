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

int A, B, C;

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>A>>B>>C;
	int wk=inf;
	wk=min(wk, A/3);
	wk=min(wk, B/2);
	wk=min(wk, C/2);
	A-=wk*3, B-=wk*2, C-=wk*2;
	int ans=wk*7, tmp=0;
	for (int st=0; st<7; st++)
	{
	//	cerr<<"\n"<<st<<": ";
		int a=A, b=B, c=C;
		for (int d=0; ;d++)
		{
	//		cerr<<d<<" ";
			if ((st+d)%7==0 || (st+d)%7==3) 
			{
				if (b==0) {
					tmp=max(tmp, d);
					break;
				}
				b--;
			}
			else if ((st+d)%7==1 || (st+d)%7==2 || (st+d)%7==5)
			{
				if (a==0){
					tmp=max(tmp, d);
					break;
				}
				a--;
			}
			else
			{
				if (c==0) {
					tmp=max(tmp, d);
					break;	
				}
				c--;
			}
		}
	}
	
	cout<<ans+tmp;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/