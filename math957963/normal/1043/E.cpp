#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 301000






int main(){
	vector<pair<long long,pair<long long,long long> > >a;
	long long b[N];
	long long c[N];
	long long xx[N];
	long long yy[N];
	long long ans[N];
	long long n, m,k;
	long long x, y, z;
	long long s;
	bool v = true;
	scanf("%I64d %I64d", &n, &m);
	f(i, n){
		scanf("%I64d %I64d", &x,&y);
		xx[i] = x;
		yy[i] = y;
		a.push_back(make_pair((x - y), make_pair(i, y)));
	}
	sort(a.begin(), a.end());
	b[0] = 0;
	f(i, n)b[i + 1] = b[i] + (a[i].first + a[i].second.second);
	c[0] = 0;
	f(i, n)c[i + 1] = c[i] + (a[i].second.second);

	f(i, n){
		ans[a[i].second.first] = i*(a[i].second.second);
		ans[a[i].second.first] += (n - i - 1)*(a[i].first + a[i].second.second);
		ans[a[i].second.first] += b[i];
		ans[a[i].second.first] += (c[n] - c[i + 1]);
	}

	f(i, m){
		scanf("%I64d %I64d", &x, &y);
		x--;
		y--;
		z = min(xx[x] + yy[y], xx[y] + yy[x]);
		ans[x] -= z;
		ans[y] -= z;
	}

	f(i, n){
		printf("%I64d", ans[i]);
		if (i < n - 1)printf(" ");
		else printf("\n");
	}


	return 0;
}