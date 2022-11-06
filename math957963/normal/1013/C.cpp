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
	vector<long long>a;
	int n;
	long long w, x, y, z;
	long long ans;
	scanf("%I64d", &n);
	f(i, (2*n)){
		scanf("%d", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	w = a[((2 * n) - 1)] - a[0];
	x = 1000000009;
	f(i, n){
		x = min(x, (a[n + i] - a[i + 1]));
	}
	y = a[n-1] - a[0];
	z = a[(2 * n) - 1] - a[n];

	ans = min((w*x), (y*z));

	printf("%I64d\n", ans);


	return 0;
}