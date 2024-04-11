#include<iostream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define MAX 3000005

const double eps=1e-9;

int n, r;
vector <pair <double, double> > V;
int X[1005];

bool EQ(double d1, double d2)
{
	return abs(d1-d2)<eps;
}

bool check(double x, double y)
{
	for (int i=0; i<V.size(); i++) if ((x-V[i].first)*(x-V[i].first)+(y-V[i].second)*(y-V[i].second)<4*r*r) return 0;
	return 1;
}

double CNP(double x, double l, double r, bool ck)
{
	if (!ck) if (check(x, l)) return l;
	
	if (EQ(l, r)) return l;
	
	double mid=(double)(l+r)/(double)(2);
	
	if (!check(x, mid)) return CNP(x, mid+eps, r, 1);
	else return CNP(x, l, mid, 1);
}

main()
{
//	freopen("test.inp", "r", stdin);
//	freopen("test.out", "w", stdout);
	
	cin>>n>>r;
	for (int i=0; i<n; i++) cin>>X[i];
	double y;
	
	V.push_back({X[0], r});
	
	for (int i=1; i<n; i++)
	{
		double beg=r;
		
		for (int j=0; j<V.size(); j++) if (!(abs(X[i]-V[j].first)>2*r)) beg=max(beg, V[j].second);
		y=CNP(X[i], beg, MAX, 0);
		
		V.push_back({(double)X[i], y});
	}
	
	for (int i=0; i<V.size(); i++) printf("%0.8f ", V[i].second);
}