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
	char a[51];
	f(i, 51)a[i] = 0;
	int n;
	int ans = 0;

	scanf("%s", a);
	n = strlen(a);

	f(i, n){
		if (a[i] == 'a' || a[i] == 'i' || a[i] == 'u' || a[i] == 'e' || a[i] == 'o' || a[i] == '1' || a[i] == '3' || a[i] == '5' || a[i] == '7' || a[i] == '9')ans++;
	}

	printf("%d\n", ans);

	return 0;
}