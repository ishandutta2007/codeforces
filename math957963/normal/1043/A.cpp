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
	s = 0;
	scanf("%d", &n);
	f(i, n){
		scanf("%d", &a[i]);
		ans += a[i];
		s = max(s, a[i]);
	}
	ans = ans * 2;
	ans = ans / n;
	ans++;
	ans = max(ans, s);
	printf("%d\n", ans);


	return 0;
}