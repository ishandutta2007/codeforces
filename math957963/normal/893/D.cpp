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
	int a[100010];
	int k[100010];
	int mx[100010];
	int s;
	int n, m, d;
	int ans = 0;
	bool z = true;
	scanf("%d %d", &n,&d);
	s = 0;
	k[0] = 0;
	f(i, n){
		scanf("%d", &a[i]);
		k[i + 1] = k[i] + a[i];
	}
	m = -1000000001;
	for (int i = n; i >= 0; i--){
		m = max(m, k[i]);
		if (i < n){
			mx[i] = d - m;
if(mx[i]<0)z=false;
		}
	}
	s = 0;

	f(i, n){
		if (a[i] == 0){
			if (k[i+1] + s < 0){
				s = mx[i];
				ans++;
				if (k[i+1] + s < 0){
					z = false;
					break;
				}
			}
		}
	}

	if (z)printf("%d\n",ans);
	else printf("-1\n");

	return 0;
}