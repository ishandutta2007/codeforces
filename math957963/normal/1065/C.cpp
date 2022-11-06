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
#define N 200010


int main(){
	int a[N];
	f(i, N)a[i] = 0;
	int n, k;
	int x, y, z;
	int s,ss, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n,&k);
	f(i, n){
		scanf("%d", &x);
		a[x]++;
	}
	s = 0;
	ss = 0;
	for(int i=N-1;i>0;i--){
		s += a[i];
		if (s == n){
			if (ss > 0)ans++;
			break;
		}
		ss += s;
		if (ss > k){
			ans++;
			ss = s;
			if (s == n)break;
		}

		if (i == 1)ans++;
	}

	printf("%d\n", ans);


	return 0;
}