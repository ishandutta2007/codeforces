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
#define N 1000


int main(){
	int a[N];
	int b[N];
	int n, m;
	int x, y, z;
	scanf("%d %d", &n, &m);
	x = 0;
	y = 0;
	f(i, n){
		scanf("%d", &a[i]);
		if (i < (n - 1))x = x^a[i];
	}
	f(i, m){
		scanf("%d", &b[i]);
		if (i < (m - 1))y = y^b[i];
	}
	if ((x^b[m - 1]) == (y^a[n - 1])){
		z = (x^b[m - 1]);
		printf("YES\n");
		f(i, (n - 1)){
			f(j, (m - 1))printf("0 ");
			printf("%d\n", a[i]);
		}
		f(i, (m - 1))printf("%d ", b[i]);
		printf("%d\n", z);
	}
	else printf("NO\n");
	
	return 0;
}