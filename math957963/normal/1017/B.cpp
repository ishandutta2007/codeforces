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
	char a[N + 1];
	char b[N + 1];
	f(i, N + 1){
		a[i] = 0;
		b[i] = 0;
	}
	int n;
	long long w, x, y, z;
	long long ans;
	ans = 0;
	scanf("%d", &n);
	scanf("%s", a);
	scanf("%s", b);
	w = 0;
	x = 0;
	y = 0;
	z = 0;
	f(i, n){
		if (a[i] == '0'&&b[i] == '0')w++;
		else if (a[i] == '0'&&b[i] == '1')x++;
		else if (a[i] == '1'&&b[i] == '0')y++;
		else if (a[i] == '1'&&b[i] == '1')z++;
	}
	ans += (w*y);
	ans += (w*z);
	ans += (x*y);

	printf("%I64d\n", ans);


	return 0;
}