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
#define N 1000010


int main(){
	char a[N + 1];
	char b[N + 1];
	f(i, N + 1){
		a[i] = 0;
		b[i] = 0;
	}
	int n;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	scanf("%s", a);
	scanf("%s", b);
	for(int k=1;k<n;k++){
		if (a[k - 1] != b[k - 1]){
			if (a[k] != b[k] && a[k - 1] != a[k]){
				ans++;
				a[k - 1] = b[k - 1];
				a[k] = b[k];
			}
			else{
				ans++;
				a[k - 1] = b[k - 1];
			}
		}
	}
	if (a[n - 1] != b[n - 1])ans++;

	printf("%I64d\n", ans);


	return 0;
}