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
#define N 500100


int main(){
	int a[N];
	int b[N];
	f(i, N){
		a[i] = 0;
		b[i] = 0;
	}
	int ab=0;
	char c[N];
	int n, k;
	int x, y;
	int ans=0;
	bool v1,v2;
	ans = 0;
	scanf("%d", &n);
	f(i, N)c[i] = 0;
	f(i, n){
		scanf("%s", c);
		k = strlen(c);
		x = 0;
		v1 = true;
		f(j, k){
			if (c[j] == '(')x++;
			else x--;
			if (x < 0)v1 = false;
		}
		y = 0;
		v2 = true;
		f(j, k){
			if (c[k-j-1] == ')')y++;
			else y--;
			if (y < 0)v2 = false;
		}
		if (v1&&v2)ab++;
		else if (v1){
			a[x]++;
		}
		else if (v2){
			b[y]++;
		}
		f(j, k)c[j] = 0;
	}
	f(i, N)ans += min(a[i], b[i]);
	ans += (ab / 2);

	printf("%d\n", ans);


	return 0;
}