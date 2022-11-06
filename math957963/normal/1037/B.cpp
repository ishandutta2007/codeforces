#include<cstdio>
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
	int n, m;
	long long k, x;
	long long ans;
	ans = 0;
	scanf("%d %I64d", &n,&k);
	f(i, n){
		scanf("%I64d", &x);
		a.push_back(x);
	}
	m = n / 2;
	sort(a.begin(), a.end());
	if (a[m] < k){
		for (int i = m; i < n; i++){
			if (a[i] < k)ans += (k - a[i]);
		}
	}
	else if (a[m]>k){
		for (int i = 0; i <= m; i++){
			if (a[i] > k)ans += (a[i] - k);
		}
	}

	printf("%I64d\n", ans);


	return 0;
}