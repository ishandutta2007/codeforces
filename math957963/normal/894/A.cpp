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
	char a[101];
	f(i, 101)a[i] = 0;
	int k, s;
	int n, m;
	int x, y, z;
	int ans = 0;

	scanf("%s", a);
	n = strlen(a);

	for (int i = 0; i < n; i++){
		if (a[i] == 'Q'){
			for (int j = i + 1; j < n; j++){
				if (a[j] == 'A'){
					for (int k = j + 1; k < n; k++){
						if (a[k] == 'Q')ans++;
					}
				}
			}
	}
	}

	printf("%d\n", ans);

	return 0;
}