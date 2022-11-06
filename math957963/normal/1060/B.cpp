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
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 200000


int main(){
	long long n, k;
	long long x;
	long long ans;
	bool v = true;
	ans = 0;
	scanf("%I64d", &n);
	k = n + 1;
	x = 1;
	ans = 0;
	while (k > 9){
		x = x * 10;
		ans += 9;
		k = k / 10;
	}
	x--;
	n -= x;
	while (n > 0){
		ans += (n % 10);
		n = n / 10;
	}

	printf("%I64d\n", ans);


	return 0;
}