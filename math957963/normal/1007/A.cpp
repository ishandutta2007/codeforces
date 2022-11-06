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
#define N 100000


int main(){
	int a[N];
	int b[N];
	f(i, N){
		a[i] = 0;
		b[i] = 0;
	}
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	f(i, n){
		b[i] = a[i];
	}
	x = 0;
	y = 0;
	while(y<n){
		if (a[x] >= b[y])y++;
		else{
			ans++;
			x++;
			y++;
		}
	}
	printf("%d\n", ans);


	return 0;
}