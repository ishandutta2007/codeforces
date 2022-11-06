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
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000

long long gc(long long x, long long y){
	if (x > y)swap(x, y);
	if (x <= 0)return y;
	if (y%x == 0)return x;
	return gc((y%x), x);
}


int main(){
	long long a, b, c, d, e, f, g, x, y, z,ans;
	scanf("%I64d %I64d %I64d", &a, &b, &c);
	scanf("%I64d %I64d %I64d", &d, &e, &f);
	g = gc(c, f);
	if (a > d){
		swap(a, d);
		swap(b, e);
	}
	ans = 0;
	x = (d - a) / g;
	y = max(a + (x*g), d);
	z = min(b + (x*g), e);
	ans = max(ans, z - y + 1);
	x++;
	y = max(a + (x*g), d);
	z = min(b + (x*g), e);
	ans = max(ans, z - y + 1);

	if (b > e){
		swap(a, d);
		swap(b, e);
	}
	x = (e - b) / g;
	y = max(a + (x*g), d);
	z = min(b + (x*g), e);
	ans = max(ans, z - y + 1);
	x++;
	y = max(a + (x*g), d);
	z = min(b + (x*g), e);
	ans = max(ans, z - y + 1);

	printf("%I64d\n", ans);


	return 0;
}