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
#define mn 200005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second

int X[mn], Y[mn], ans[mn];
int n;
vector <pii> W[mn];

int CNP(int id, int u, int l, int r)
{
//	cerr<<id<<" "<<u<<" "<<l<<" "<<r<<"\n";
	if (u<=W[id][l].XX) return l-1;
	if (u>W[id][r].XX) return r;
	
	int mid=(l+r)/2;
	if (u>W[id][mid].XX) return CNP(id, u, mid+1, r);
	else return CNP(id, u, l, mid);
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
	
	for (int i=1; i<mn; i++) for (int j=i*i+i; j<mn; j+=i)
	{
		if ((j/i)%2==i%2)W[j].push_back({((j/i+i)*(j/i+i))/4, ((j/i-i)*(j/i-i))/4});
	}
	
	for (int i=1; i<mn; i++) 
	{
		W[i].push_back({-inf, -inf});
		sort(W[i].begin(), W[i].end());
	}
	
	cin>>n;
	for (int i=2; i<=n; i+=2) cin>>X[i];
	Y[n]=W[X[n]].back().XX, Y[n-1]=W[X[n]].back().YY;
	if (W[X[n]].size()==1)
	{
		cout<<"No";
		return 0;
		
	}
	for (int i=n-2; i>0; i-=2)
	{
		int c=CNP(X[i], Y[i+1], 0, W[X[i]].size()-1);
//		cerr<<Y[i+1]<<" "<<X[i]<<" "<<c<<"\n";
//		cerr<<X[i]<<" size()="<<W[X[i]].size()<<":\n";
//		for (pii j:W[X[i]]) cerr<<j.XX<<" "<<j.YY<<"\n";
//		cerr<<"\n";
		if (c<=0)
		{
			cout<<"No";
			return 0;
		}
		Y[i-1]=W[X[i]][c].YY;
		Y[i]=W[X[i]][c].XX;
	}
	
	cout<<"Yes\n";
	for (int i=1; i<=n; i++) 
	{
	//	ans[i]=Y[i]-Y[i-1];
		cout<<Y[i]-Y[i-1]<<" ";
	}
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/