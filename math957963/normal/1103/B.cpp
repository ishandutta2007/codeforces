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
	char a[11];
	f(i, 11)a[i] = 0;
	int n, k;
	long long x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	long long l = 1;
	long long r = 100000001;
	long long m;
	scanf("%s", a);
	while (true){
		if (a[0] != 's')return 0;
		x = 1;
		f(i, 30){
			printf("? %I64d %I64d\n", x, 2 * x);
			fflush(stdout);
			f(i, 11)a[i] = 0;
			scanf("%s", a);
			if (a[0] == 'x'){
				l = x;
				r = (2 * x) + 1;
				break;
			}
			else x *= 2;
		}
		if (l == 1){
			printf("? 2 1\n");
			fflush(stdout);
			f(i, 11)a[i] = 0;
			scanf("%s", a);
			if (a[0] == 'x')r = 2;
			else l = 2;
		}
		else{
			while (l + 1 < r){
				m = (l + r) / 2;
				m--;
				printf("? %I64d %I64d\n", m / 2, m);
				fflush(stdout);
				f(i, 11)a[i] = 0;
				scanf("%s", a);
				if (a[0] == 'x')r = m + 1;
				else l = m + 1;
			}
		}
		printf("! %I64d\n", l);
		fflush(stdout);
		f(i, 11)a[i] = 0;
		scanf("%s", a);
	}


	return 0;
}