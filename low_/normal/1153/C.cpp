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

int n;
string S;

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
	if (S[0]==')' || S[n-1]=='(' || n%2==1) 
	{
		cout<<":(";
		return 0;
	}
	
	S=S.substr(1, n-2);
	n-=2;
	int cntO=0, cntC=0;
	for (int i=0; i<n; i++) cntO+=(S[i]=='('), cntC+=(S[i]==')');
	cntO=n/2-cntO, cntC=n/2-cntC;
	if (cntO<0 || cntC<0) 
	{
		cout<<":(";
		return 0;
	}
	
	for (int i=0; i<n; i++) if (S[i]=='?')
	{
		if (cntO>0) S[i]='(', cntO--;
		else S[i]=')', cntC--;
	}
	int t=0;
	for  (int i=0; i<n; i++) 
	{
		if (S[i]=='(') t++;
		else t--;
		if (t<0)
		{
			cout<<":(";
			return 0;
		}
	}
	if (t>0)
	{
		cout<<":(";
		return 0;
	}
	
	cout<<"("<<S<<")";
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/