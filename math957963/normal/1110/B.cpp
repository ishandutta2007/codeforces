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
#define N 200000


int main(){
	vector<long long>b;
	long long a[N];
	f(i, N)a[i] = 0;
	long long n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%I64d %I64d %I64d", &n, &k, &s);
	f(i, n){
		scanf("%I64d", &a[i]);
		if (i > 0)b.push_back(a[i] - a[i - 1]);
	}
	sort(b.begin(), b.end());
	ans = s;
	f(i, n - s){
		ans += b[i];
	}

	printf("%I64d\n", ans);


	return 0;
}