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
	int a[8];
	char c[5];
	f(i, 8)a[i] = 1000000;
	int n, k;
	int x, y, z;
	int ans;
	ans = 999999;

	scanf("%d", &n);
	f(i, n){
		f(i, 5)c[i] = 0;
		scanf("%d", &x);
		scanf("%s", c);
		k = strlen(c);
		y = 0;
		f(i, k){
			if (c[i] == 'A')y++;
			else if (c[i] == 'B')y += 2;
			else if (c[i] == 'C')y += 4;
		}
		if (y < 8){
			a[y] = min(a[y], x);
		}
	}
	f(i, 8){
		if (i == 7){
			ans = min(ans, a[i]);
		}
		f(j, 8){
			if ((i | j)== 7){
				ans = min(ans, a[i] + a[j]);
			}
			f(ii, 8){
				if (((i | j) | ii) == 7){
					ans = min(ans, a[i] + a[j] + a[ii]);
				}
			}
		}
	}
	if (ans == 999999)printf("-1\n");
	else printf("%d\n", ans);


	return 0;
}