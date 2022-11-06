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
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200010


int main() {
	long long a[N];
	long long b[N];
	f(i, N) {
		a[i] = 0;
		b[i] = 0;
	}
	long long n,m,x, y, k,z,ans;
	scanf("%I64d %I64d %I64d %I64d %I64d",&n,&m,&x,&y,&k);
	f(i, n)scanf("%I64d", &a[i]);
	f(i, m)scanf("%I64d", &b[i]);
	if (k >= min(n, m)) {
		printf("-1\n");
		return 0;
	}
  ans=0;
  z=0;
	f(i, k+1) {
		if ((a[i] + x) > b[m - k+i - 1]) {
			printf("-1\n");
			return 0;
		}
      while(a[i]+x>b[z])z++;
      ans=max(ans,b[z+k-i]+y);
	}
printf("%I64d\n",ans);
	return 0;
}