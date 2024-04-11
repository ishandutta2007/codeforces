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
	char a[N + 2];
	int b[N + 2];
	f(i, N + 2){
		a[i] = 0;
		b[i] = 0;
	}
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%s", a);
	n = strlen(a);
	a[n] = 'b';
	f(i, n){
		if (a[i] != a[i + 1])b[i] = 1;
	}
	f(i, n){
		printf("%d", b[i]);
		if (i < n - 1)printf(" ");
		else printf("\n");
	}



	return 0;
}