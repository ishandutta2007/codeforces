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
#define f(i,n) for(long long i=0;i<(long long)(n);i++)
#define N 200000






int main(){
	vector<long long>a;
	vector<long long>b;
	long long n, x, y, ans;
	ans = 0;
	scanf("%I64d", &n);
	f(i, n){
		scanf("%I64d %I64d", &x, &y);
		a.push_back(x);
		b.push_back(y);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ans = n;
	f(i, n){
		ans += max(a[i], b[i]);
	}
	printf("%I64d\n", ans);


	return 0;
}