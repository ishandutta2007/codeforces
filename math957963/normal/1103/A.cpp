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
	char a[N + 1];
	f(i, N + 1)a[i] = 0;
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%s", a);
	n = strlen(a);
	x = 0;
	y = 0;
	f(i, n){
		if (a[i] == '0'){
			printf("1 %d\n", x + 1);
			x = (x + 1) % 4;
		}
		else{
			printf("3 %d\n", y + 1);
			y = (y + 2) % 4;
		}
	}

	return 0;
}