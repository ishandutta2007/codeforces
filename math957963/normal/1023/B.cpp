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
	long long n, k, ans;
	ans = 0;
	scanf("%I64d %I64d", &n, &k);
	if (n < k){
		ans = (2 * n) - k + 1;
	}
	else{
		ans = k - 1;
	}
	if (ans < 0)ans = 0;
	ans = ans / 2;

	printf("%I64d\n", ans);


	return 0;
}