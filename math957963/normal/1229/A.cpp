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
#define N 200000
 
 
int main() {
	vector<pair<long long,long long> > a;
	long long b[N];
	bool c[N];
	f(i, N) {
		b[i] = 0;
		c[i] = true;
	}
	long long n;
	long long x, y;
	long long ans;
	bool v;
	bool vv;
	ans = 0;
	scanf("%I64d", &n);
	f(i, n) {
		scanf("%I64d", &b[i]);
	}
	f(i, n) {
		scanf("%I64d", &x);
		a.push_back(make_pair(b[i], x));
	}
	sort(a.begin(), a.end(), greater<pair<long long, long long> >());
	f(i, n) {
		vv = false;
		f(j, n) {
			if ((i != j)&&c[j]) {
				x = a[i].first;
				y = a[j].first;
				if (x <= y) {
					v = true;
					f(ii, 60) {
						if ((x % 2 == 1) && (y % 2 == 0)){
v = false;
break;
}
x=x/2;
y=y/2;
					}
					if (v)vv = true;
				}
			}
			if (vv)break;
		}
		if (vv)ans += a[i].second;
		else c[i] = false;
	}
	printf("%I64d\n", ans);
	return 0;
}