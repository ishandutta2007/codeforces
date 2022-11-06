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
	bool t[31];
	int n, k;
	int x;
	int l, r, mid;
	l = 0;
	scanf("%d %d", &r,&n);
	r++;
	f(i, n){
		printf("1\n");
		fflush(stdout);
		scanf("%d", &x);
		if (x != 1 && x != -1)return 0;
		else if (x == 1)t[i] = true;
		else t[i] = false;
	}
	k = 0;
	while (true){
		mid = (l + r) / 2;
		printf("%d\n",mid);
		fflush(stdout);
		scanf("%d", &x);
		if (!t[k])x = -x;
		if (x != 1 && x != -1)return 0;
		else if (x == 1)l = mid+1;
		else r = mid;
		k = (k + 1) % n;
	}


	return 0;
}