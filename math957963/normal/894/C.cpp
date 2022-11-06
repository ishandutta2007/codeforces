#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009
int main(void){
	vector<int>a;
	int n, x;
	bool z;
	scanf("%d", &n);
	z = true;
	for (int i = 0; i < n; i++){
		scanf("%d",&x);
		a.push_back(x);
		if (i > 0){
			if (x%a[0] != 0)z = false;
		}
	}
	if (z == true){
		printf("%d\n", (2 * n) - 1);
		for (int i = 0; i < n-1; i++){
			printf("%d %d ", a[i], a[0]);
		}
		printf("%d\n", a[n - 1]);
	}
	else printf("-1\n");
	return 0;
}