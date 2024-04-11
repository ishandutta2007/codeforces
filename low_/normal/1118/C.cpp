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
int ans[25][25];
int cnt[1005];

vector <int> dv0, dv1, dv2;

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	int t;
	for (int i=1; i<=n*n; i++) 
	{
		cin>>t;
		cnt[t]++;
	}
	
	for (int i=1; i<=1000; i++) if (cnt[i]%2==1)
	{
		dv1.push_back(i);
		cnt[i]--;
	}
	
	for (int i=1; i<=1000; i++) if (cnt[i]%4==2)
	{
		dv2.push_back(i);
		cnt[i]-=2;
	}
	
	for (int i=1; i<=1000; i++)
	{
		for (int j=0; j<cnt[i]/4; j++) dv0.push_back(i);
	}
	
	if (n%2==0)
	{
		if (dv1.size()>0 || dv2.size()>0) 
		{
			cout<<"NO";
			return 0;
		}
		
		int p=0;
		for (int i=0; i<n/2; i++) for (int j=0; j<n/2; j++)
		{
			ans[i][j]=ans[i][n-j-1]=ans[n-i-1][j]=ans[n-i-1][n-j-1]=dv0[p];
			p++;
		}
	}
	else
	{
		if (dv1.size()>1 || dv2.size()>(n/2)*2)
		{
			cout<<"NO";
			return 0;
		}
		
		ans[n/2][n/2]=dv1[0];
		while (dv2.size()<(n/2)*2)
		{
			dv2.push_back(dv0.back());
			dv2.push_back(dv0.back());
			dv0.pop_back();
		}
		
		int p=0;
		for (int i=0; i<n/2; i++) for (int j=0; j<n/2; j++)
		{
			ans[i][j]=ans[i][n-j-1]=ans[n-i-1][j]=ans[n-i-1][n-j-1]=dv0[p];
			p++;
		}
		
		p=0;
		for (int i=0; i<n/2; i++)
		{
			ans[i][n/2]=ans[n-i-1][n/2]=dv2[p];
			p++;
		}
		for (int j=0; j<n/2; j++) if (j!=n/2)
		{
			ans[n/2][j]=ans[n/2][n-j-1]=dv2[p];
			p++;
		}
	}
	
	cout<<"YES\n";
	for (int i=0; i<n; i++) 
	{
		for (int j=0; j<n; j++) cout<<ans[i][j]<<" ";
		cout<<"\n";
	}
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/