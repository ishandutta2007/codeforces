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


int main(){
	long long n, k;
	long long x, y, z;

	scanf("%I64d %I64d", &n, &k);
	x = n - (k * 2);
	if (x < 0)x = 0;
	f(i, n){
		y = i*(i + 1);
		y = y / 2;
		if (k <= y){
			z = n - i - 1;
			break;
		}
	}
	if (k == 0)z = n;

	printf("%I64d %I64d\n", x, z);


	return 0;
}