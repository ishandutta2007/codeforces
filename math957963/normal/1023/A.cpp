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
	char a[N + 1];
	char b[N + 1];
	f(i, N + 1){
		a[i] = 0;
		b[i] = 0;
	}
	int n, m;
	int x, y;
	bool ans = true;
	bool v = false;
	scanf("%d %d", &n, &m);
	scanf("%s", a);
	scanf("%s", b);
	f(i, n){
		if (a[i] == '*')v = true;
	}
	if (v){
		if (n > m + 1){
			ans = false;
		}
		else{
			x = 0;
			while (a[x] != '*'){
				if (a[x] != b[x]){
					ans = false;
					break;
				}
				x++;
			}
			x = n - 1;
			y = m - 1;
			while (a[x] != '*'){
				if (a[x] != b[y]){
					ans = false;
					break;
				}
				x--;
				y--;
			}
		}
	}
	else{
		if (n != m)ans = false;
		else{
			f(i, n){
				if (a[i] != b[i])ans = false;
			}
		}
	}
	if(ans)printf("YES\n");
	else printf("NO\n");


	return 0;
}