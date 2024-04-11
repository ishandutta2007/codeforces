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
int mcd[mn*10];

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
	S=" "+S;
	for (int i=1; i<=n; i++) mcd[i]=mcd[i-1]+(S[i]=='(')-(S[i]==')');
	
	
	
	int ans=0;
	if (mcd[n]==2) //change ( to )
	{
		for (int i=n; i>0; i--)
		{
			if (mcd[i]<=1) break;
			if (S[i]=='(') ans++; 
		}
		for (int i=1; i<=n; i++) if (mcd[i]<0) ans=0;
	}
	else if (mcd[n]==-2) //change ) to (
	{
		for (int i=1; i<=n; i++)
		{
			if (S[i]==')') ans++;
			if (mcd[i]<0) break; 
		}
		for (int i=1; i<=n; i++) if (mcd[i]<-2) ans=0;
	}
	
	cout<<ans;
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/