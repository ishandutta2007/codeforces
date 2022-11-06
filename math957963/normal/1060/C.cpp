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
#define N 10010


int main(){
	long long a[N];
	long long b[N];
	long long ma[N];
	long long mb[N];
	f(i, N){
		a[i] = 0;
		b[i] = 0;
	}
	int n,m,aa,bb,ans;
	long long x;
	long long s;
	bool v = true;
	scanf("%d %d", &n, &m);
	a[0] = 0;
	f(i, n){
		scanf("%I64d", &x);
		a[i + 1] = a[i] + x;
	}
	b[0] = 0;
	f(i, m){
		scanf("%I64d", &x);
		b[i + 1] = b[i] + x;
	}
	scanf("%I64d", &s);
	f(i, n){
		ma[i] = 10000000000;
		f(j, n - i){
			ma[i] = min(a[i + j + 1] - a[j], ma[i]);
		}
	}
	f(i, m){
		mb[i] = 10000000000;
		f(j, m - i){
			mb[i] = min(b[i + j + 1] - b[j], mb[i]);
		}
	}
	aa = 0;
	bb = m - 1;
	ans = 0;
	while (aa < n&&bb>=0){
		if (ma[aa] * mb[bb] <= s){
			ans = max(ans, (aa + 1)*(bb + 1));
			aa++;
		}
		else bb--;
	}

	printf("%d\n", ans);


	return 0;
}