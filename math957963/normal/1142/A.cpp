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

long long gcd(long long x, long long y) {
	if (x < 0)x = -x;
	if (y < 0)y = -y;
	if (x > y)swap(x, y);
	if (x == 0)return y;
	if (y%x == 0)return x;
	return gcd(y%x, x);
}

int main() {
	long long x, y, z;
	long long n ,k;
	long long mi, ma;
	scanf("%I64d %I64d", &n, &k);
	scanf("%I64d %I64d", &x, &y);
	mi = 0;
	ma = 100000000000000;
	f(i, n) {
		z = gcd((k*i) + y - x, (n*k));
		if (z < ma)ma = z;
		if (z > mi)mi = z;
		z = gcd((k*i)+x - y, (n*k));
		if (z < ma)ma = z;
		if (z > mi)mi = z;
		z = gcd((k*i)+x + y, (n*k));
		if (z < ma)ma = z;
		if (z > mi)mi = z;
		z = gcd((k*i) - x - y, (n*k));
		if (z < ma)ma = z;
		if (z > mi)mi = z;
	}
	ma = (n*k) / ma;
	mi = (n*k) / mi;


	printf("%I64d %I64d\n", mi,ma);


	return 0;
}