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
	char a[N + 1];
	f(i, N + 1)a[i] = 0;
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &x);
	f(qq, x){
		scanf("%I64d %I64d", &ans,&s);
		ans *= 9;
		ans += (s - 9);
		printf("%I64d\n", ans);
		}

	return 0;
}