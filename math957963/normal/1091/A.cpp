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
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 200000

int main(){
	int x, y, z;
	int s, ans;
	scanf("%d %d %d", &x, &y, &z);
	s = min(x, min(y - 1, z - 2));
	ans = s * 3;
	ans += 3;
	printf("%d\n", ans);


	return 0;
}