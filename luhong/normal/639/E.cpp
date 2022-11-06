#include <iostream>
#include <cstdio>
#include <algorithm>
#define MN 151000

typedef long long ll;

struct xxx{
	int p, t;
	ll tl, tr;
} d[MN];

ll s = 0; int n; 

bool operator < (xxx a, xxx b) {return 1ll * a.p * b.t > 1ll * b.p * a.t;}
bool operator == (xxx a, xxx b) {return 1ll * a.p * b.t == 1ll * b.p * a.t;}

bool cmp(xxx a, xxx b) {return a.p > b.p;}

bool check(double c)
{
	double Min = 1e18;
	for(int i = 1; i <= n; i++)
	{
		int j = i;
		while(j <= n && d[j].p == d[i].p) j++; j--;
		
		for(int k = i; k <= j; k++)
			if(d[k].p * (1.0 - c * (d[k].tl + d[k].t) / s) > Min) return 0;
		
		for(int k = i; k <= j; k++)
			Min = std::min(Min, d[k].p * (1.0 - c * d[k].tr / s));
		
		i = j;
	}
	return 1;
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &d[i].p);
	for(int i = 1; i <= n; i++) scanf("%d", &d[i].t);
	std::sort(d + 1, d + n + 1);
	for(int i = 1; i <= n; i++)
	{
		int j = i;
		while(j <= n && d[j] == d[i]) j++; j--;
		for(int k = i; k <= j; k++) d[k].tl = s;
		for(int k = i; k <= j; k++) s += d[k].t;
		for(int k = i; k <= j; k++) d[k].tr = s;
		i = j;
	}
	std::sort(d + 1, d + n + 1, cmp);
	double l = 0, r = 1;
	for(int i = 1; i <= 60; i++)
	{
		double mid = (l + r) / 2;
		if(check(mid)) l = mid;
		else r = mid;
	}
	printf("%.10lf\n", r);
}