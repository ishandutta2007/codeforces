#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int main(void){
	int a[100][100];
	int k;
	int n,m;
	int s,max,z,la,co;
	int x;
	int ans1, ans2;


	scanf("%d %d %d", &n,&m,&k);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
		}
	}
	ans1 = 0;
	ans2 = 0;
	for (int j = 0; j < m; j++){
		s = 0;
		co = 0;
		for (int i = 0; i < k; i++){
			s = s + a[i][j];
		}
		max = s;
		z = 0;
		la = 0;
		for (int i = 0; i < n - k; i++){
			s = s - a[i][j] + a[k + i][j];
			if (a[i][j] == 1){
				if (z == 1){
					la = co;
					z = 0;
				}
				co++;
			}
			if (s > max){
				max = s;
				z = 1;
			}
		}
		if (z == 1){
			la = co;
		}
		ans1 += max;
		ans2 += la;
	}
	printf("%d %d", ans1,ans2);

	return 0;
}