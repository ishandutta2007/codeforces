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
	int a[N];
	f(i, N)a[i] = 0;
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &k,&n);
	s = 0;
	f(i, n){
		scanf("%d", &x);
		x--;
		a[x]++;
		if (a[x] == 1)s++;
		if (s >= k){
			f(j, k){
				a[j]--;
				if (a[j] <= 0)s--;
			}
			printf("1");
		}
		else printf("0");
	}

	printf("\n");


	return 0;
}