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
#define N 20000


int main(){
	int a[N];
	int b[N];
	f(i, N){
		a[i] = 0;
		b[i] = 0;
	}
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n, &k);
	k--;
	f(i, n){
		scanf("%d", &a[i]);
	}
	f(i, n){
		scanf("%d", &b[i]);
	}
	if (a[0] == 0){
		printf("NO\n");
		return 0;
	}
	if (a[k] == 1){
		printf("YES\n");
		return 0;
	}
	if (b[k] == 0){
		printf("NO\n");
		return 0;
	}
	while (k < n){
		if (a[k] == 1 && b[k] == 1){
			printf("YES\n");
			return 0;
		}
		k++;
	}
	printf("NO\n");
	return 0;


	return 0;
}