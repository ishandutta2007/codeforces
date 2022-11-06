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
	vector<int> b[100000];
	int n, k, m;
	int x, y, z;
	int ans = 0;

	scanf("%d %d %d", &n, &k, &m);
	f(i, n){
		scanf("%d", &y);
		x = y % m;
		b[x].push_back(y);
	}
	f(i, m){
		if (b[i].size() >= k&&ans==0){
			printf("Yes\n");
			f(j, k){
				printf("%d", b[i][j]);
				if (j < k - 1)printf(" ");
			}
			printf("\n");
			ans = 1;
		}
	}

	if(ans==0)printf("No\n");

	return 0;
}