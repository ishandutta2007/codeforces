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
	long long n, k;
	long long x, y;
	vector<long long>a, b;

	scanf("%I64d %I64d", &n, &k);
	y = n + k;
	x = 0;
	while ((2 * y) >= (x*(x + 1)))x++;
	x--;
	for (int i = x; i > 0; i--){
		if (n >= i){
			n -= i;
			a.push_back(i);
		}
		else b.push_back(i);
	}
	printf("%d\n", a.size());
	f(i, a.size()){
		printf("%I64d", a[i]);
		if (i < a.size() - 1)printf(" ");
	}
	printf("\n");
	printf("%d\n", b.size());
	f(i, b.size()){
		printf("%I64d", b[i]);
		if (i < b.size() - 1)printf(" ");
	}
			printf("\n");


	return 0;
}