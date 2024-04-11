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
#define N 300010


int main(){
	char a[N + 1];
	char b;
	f(i, N + 1)a[i] = 0;
	int n;
	int x;
	long long s1,s2, ans;
	ans = 0;
	scanf("%d %I64d %I64d", &n, &s1, &s2);
	scanf("%s", a);
	b = '1';
	x = 0;
	f(i, n){
		if (b=='1' && a[i]=='0')x++;
		b = a[i];
	}
	if (x > 0)ans += s2;
	x--;
	while (x > 0){
		ans += min(s1, s2);
		x--;
	}

	printf("%I64d\n", ans);


	return 0;
}