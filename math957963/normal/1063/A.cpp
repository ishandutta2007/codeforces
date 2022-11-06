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
	int b[300];
	f(i, 300)b[i] = 0;
	f(i, N + 1)a[i] = 0;
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	scanf("%s", a);
	f(i, n){
		b[a[i]]++;
	}
	f(i, 300){
		f(j, b[i]){
			printf("%c", i);
		}
	}

	printf("\n");


	return 0;
}