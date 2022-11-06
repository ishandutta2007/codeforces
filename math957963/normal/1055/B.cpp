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
#define N 200000


int main(){
	long long a[N];
	f(i, N){
		a[i] = 0;
	}
	int ans;
	long long k;
	int n, q;
	int x, y;
	long long s;
	scanf("%d %d %lld", &n, &q, &k);
	f(i, n){
		scanf("%I64d", &a[i]);
	}
	ans = 0;
	f(i, n){
		if (a[i] > k){
			if (i == 0)ans++;
			else{
				if (a[i - 1] <= k)ans++;
			}
		}
	}
	f(qq, q){
		scanf("%d", &x);
		if (x == 0){
			printf("%d\n", ans);
		}
		else{
			scanf("%d %I64d", &y, &s);
			y--;
			if (a[y] <= k && (a[y] + s) > k){
				if (y == 0){
					if (n == 1)ans++;
					else{
						if (a[1] <= k)ans++;
					}
				}
				else if (y == n - 1){
					if (n == 1)ans++;
					else{
						if (a[n - 2] <= k)ans++;
					}
				}
				else{
					if (a[y - 1] > k&&a[y + 1] > k)ans--;
					else if (a[y - 1] <= k&&a[y + 1] <= k)ans++;
				}
			}
			a[y] += s;
		}
	}


	return 0;
}