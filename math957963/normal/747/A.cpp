#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main(void){
int a[100000];
int s;
	int n;
	int m;
	int x, y;
	int p, q;
	int v;
	m = 1;
	scanf("%d",&n);
	for (int i = 1; i <= n; i++){
		if (n%i == 0){
			if ((n/i) >= i){
				m = i;
			}
		}
	}
	printf("%d %d\n", m, n / m);

	return 0;
}