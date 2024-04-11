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
#define PA(a,b) std::pair(a,b)
#define MOD 1000000009

int main(void){
	vector<int> a;
	int n, m, k;
	int x, y, z;
	int ans = 0;

	scanf("%d", &n);
	f(i, 100){
		k = n - i;
		if (k > 0){
			x = k;
			while (k > 0){
				x += (k % 10);
				k = k / 10;
			}
			if (x == n)a.push_back(n - i);
		}
	}
	printf("%d\n", a.size());
	f(i,a.size())printf("%d\n",a[a.size()-i-1]);

	return 0;
}