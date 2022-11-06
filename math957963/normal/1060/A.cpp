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
#define N 200


int main(){
	char a[N + 1];
	f(i, N + 1)a[i] = 0;
	int n, k;
	int ans;
	scanf("%d", &n);
	scanf("%s", a);
	k = 0;
	f(i, n){
		if (a[i] == '8')k++;
	}
	n = n / 11;
	n = min(n, k);
if(n<0)n=0;
	printf("%d\n", n);


	return 0;
}