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
	int n, k;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d %d", &n, &z, &k);
	s = 0;
	f(i, n){
		scanf("%d %d", &x,&y);
		ans += (x - s) / k;
		s = x + y;
	}
	ans += (z - s) / k;

	printf("%d\n", ans);


	return 0;
}