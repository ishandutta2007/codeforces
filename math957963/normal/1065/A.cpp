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


int main(){
	int n;
	long long x, y, z;
	long long s, ans;

	scanf("%d", &n);
	f(i, n){
		ans = 0;
		scanf("%I64d %I64d %I64d %I64d",&s, &x, &y, &z);
		ans = s / z;
		ans += (ans / x)*y;
		printf("%I64d\n", ans);
	}



	return 0;
}