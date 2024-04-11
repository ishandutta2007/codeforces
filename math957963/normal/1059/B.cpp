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
#define N 1010


int main(){
	bool a[N][N];
	bool b[N][N];
	bool b2[N][N];
	f(i, N){
		f(j, N){
			a[i][j] = true;
			b[i][j] = false;
			b2[i][j] = false;
		}
	}

	char c[N];
	int n,m, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n,&m);
	f(i, n){
		scanf("%s", c);
		f(j, m){
			if (c[j] == '.'){
				if (i > 0){
					if (j > 0){
						a[i - 1][j - 1] = false;
					}
					a[i - 1][j] = false;
					if (j < m-1){
						a[i - 1][j + 1] = false;
					}
				}
				if (j > 0){
					a[i][j - 1] = false;
				}
				if (j < m - 1){
					a[i][j + 1] = false;
				}
				if (i < n - 1){
					if (j > 0){
						a[i + 1][j - 1] = false;
					}
					a[i + 1][j] = false;
					if (j < m - 1){
						a[i + 1][j + 1] = false;
					}
				}
			}
			else b[i][j] = true;
		}
	}

	for (int i = 1; i < n - 1; i++){
		for (int j = 1; j < m - 1; j++){
			if (a[i][j]){
				f(ii, 3){
					f(jj, 3){
						if (ii != 1 || jj != 1){
							b2[i + ii - 1][j + jj - 1] = true;
						}
					}
				}
			}
		}
	}
	f(i, n){
		f(j, m)if (b[i][j] != b2[i][j])v = false;
	}

	if(v)printf("YES\n");
	else printf("NO\n");


	return 0;
}