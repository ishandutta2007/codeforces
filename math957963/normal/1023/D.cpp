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
	int a[N + 1];
	int b[N + 1];
	int s[N + 1];
	int t[N + 1];
	vector<int>c[N + 1];
	f(i, N+1){
		a[i] = 0;
		b[i] = i;
		s[i] = -1;
		t[i] = 200001;
		c[i].clear();
	}
	int n, k;
	int x, y, z;
	bool v1 = false;
	bool v2 = false;
	bool ans = true;
	scanf("%d %d",&n,&k);
	f(i, n){
		scanf("%d", &a[i]);
		if (a[i] == k)v1 = true;
		if (a[i] == 0)v2 = true;
	}
	if ((!v1) && (!v2))ans = false;
	else{
		f(i, n){
			if (a[i] == 0){
				if (!v1){
					a[i] = k;
					v1 = true;
				}
				else if (i == 0){
					a[0] = 1;
				}
				else{
					a[i] = a[i - 1];
				}
			}
		}
		f(i, n){
			if (s[a[i]] < 0)s[a[i]] = i;
			c[a[i]].push_back(i);
		}
		f(i, n){
			if (t[a[n - i - 1]] > 200000)t[a[n - i - 1]] = n - i - 1;
		}
		for(int i=k;i>0;i--){
			if (s[i] >= 0){
				f(j, c[i].size())b[c[i][j]] = c[i][j] + 1;
				if(s[i]!=t[i]){
					x = s[i] + 1;
					while (x < t[i]){
						if (b[x] == x){
							ans = false;
							break;
						}
                      x=b[x];
					}
					b[s[i]] = t[i] + 1;
				}
			}
			if (!ans)break;
		}
	}

	if (ans){
		printf("YES\n");
		f(i, n){
			printf("%d", a[i]);
			if (i < n - 1)printf(" ");
			else printf("\n");
		}
	}
	else printf("NO\n");
	
	return 0;
}