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
#define mod 1000000007
#define FLN "test"
#define pii pair <int, int>
#define XX first
#define YY second
#define matrix vector <vector <int> >

matrix operator * (matrix a, matrix b)
{
	matrix ret;
	ret.assign(a.size(), {});
	for (int i=0; i<ret.size(); i++) ret[i].assign(b[0].size(), 0);
	for (int i=0; i<a.size(); i++) for (int j=0; j<b[0].size(); j++)
	{
		for (int ij=0; ij<b.size(); ij++) ret[i][j]=(ret[i][j]+a[i][ij]*b[ij][j])%mod;
	}
	return ret;
}

matrix POW(matrix u, int v)
{
	if (v==1) return u;
	matrix mid=POW(u, v/2);
	if (v%2==0) return (mid*mid);
	else return ((mid*mid)*u);
}

matrix U, V;

int n, m;

signed main()
{
#ifdef lowie
	freopen(FLN".inp", "r", stdin);
	freopen(FLN".out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	if (n<m) 
	{
		cout<<1;
		return 0;
	}
	U={{}};
	U[0].assign(m, 1);
	V.assign(m, {});
	for (int i=0; i<m; i++) V[i].assign(m, 0);
	for (int i=0; i<m-1; i++) V[i][i+1]=1;
	V[m-1][0]=V[m-1][m-1]=1;
	
	V=POW(V, n-m+1);
	U=U*V;
	cout<<U[0][m-1];
}

// PLEASE REMOVE "cout" AND "cerr" DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/