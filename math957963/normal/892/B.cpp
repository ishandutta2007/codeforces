#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009

int main(void){
	vector<int>a;
	int n;
	int x;
	int ans = 0;

	scanf("%d", &n);

		f(i, n){
			scanf("%d", &x);
			a.push_back(x);
		}
		reverse(a.begin(),a.end());
		x = 0;
		f(i, n){
			if (x <= 0)ans++;
			x = max(x - 1, a[i]);
		}
		printf("%d\n", ans);
	return 0;
}