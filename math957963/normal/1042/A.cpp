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
	int x;
	int s, ans;
	bool v = true;
	s = 0;
	ans = 0;
	scanf("%d", &n);
	scanf("%d", &k);
	s += k;
	f(i, n){
		scanf("%d", &x);
		ans = max(ans, x);
		s += x;
	}
	if (s%n == 0)s = s / n;
	else s = (s / n) + 1;
	s = max(ans, s);
	ans += k;

	printf("%d %d\n", s, ans);


	return 0;
}