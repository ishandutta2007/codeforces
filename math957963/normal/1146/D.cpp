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
#define N 400000

long long gcd(long long x, long long y) {
	if (x > y)swap(x, y);
	if (x <= 0)return y;
	if (y%x == 0)return x;
	return gcd(y%x, x);
}


int main() {
	vector<long long>a;
	long long b[N];
	bool c[N];
	f(i, N) {
		b[i] = 0;
		c[i] = false;
	}
	int n, k;
	long long g;
	long long x, y, z, xx, yy,zz;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d %I64d %I64d", &z, &x, &y);
	g = gcd(x, y);
	a.push_back(0);
	c[0] = true;
	xx = 0;

  	while (true) {
		if (xx >= y)xx -= y;
		else xx += x;
		if (c[xx])break;
		else c[xx] = true;
		a.push_back(xx);
	}
  
  
  
  
	xx = 0;
	yy = 0;
	zz = 0;
	
  
  while (true) {
		if (xx < a[yy]){
			b[xx] = yy;
			zz = max(zz, yy);
			xx++;
		}
		else yy++;
		if (yy >= a.size())break;
	}
	ans = 0;
	if (z < (x + y - g)) {
		f(i, z+1)ans += b[i];
		printf("%I64d\n", ans);
      return 0;
	}
	f(i, x + y - g){
      ans += b[i];
    }
	xx = (x + y) / g;
	yy = z / g;
	zz = (xx + yy)*(yy - xx + 1) / 2;
	zz *= g;
	ans += zz;
	zz = (z%g) + 1;
	zz *= ((z / g) + 1);
	ans += zz;

  

	printf("%I64d\n", ans);


	return 0;
}