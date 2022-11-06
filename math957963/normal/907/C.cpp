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
	char b[2];
	char a[100010];
	f(i, 100010)a[i] = 0;
	bool ans[26];
	f(i, 26)ans[i] = true;
	bool c[26];
	int ansnum = 26;
	int k;
	int n;
	int z = 0;

	scanf("%d", &n);
	k = 0;
	f(tt, n){
		f(i, 26)c[i] = false;
		f(i, k+1)a[i] = 0;
		scanf("%s", b);
		scanf("%s", a);
		k = strlen(a);
		if (ansnum > 1){
			if (b[0] == '!'){
				f(i, k){
					c[a[i] - 97] = true;
				}
				f(i, 26){
					if (c[i] == false && ans[i] == true){
						ansnum--;
						ans[i] = false;
					}
				}
			}
			else if (b[0] == '.'){
				f(i, k){
					c[a[i] - 97] = true;
				}
				f(i, 26){
					if (c[i] == true && ans[i] == true){
						ansnum--;
						ans[i] = false;
					}
				}
			}
			else{
				if (ans[a[0] - 97] == true){
					ansnum--;
					ans[a[0] - 97] = false;
				}
			}
	}
		else{
			if (tt < n - 1){
				if (b[0] == '!' || b[0] == '?')z++;
			}
		}
	}

	printf("%d\n", z);

	return 0;
}