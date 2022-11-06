#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std;
int main(void){
	int n, m;
	int x, y, z;
	int ans=0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		ans = 0;
		if (x % 2 == 1){
			if (x < 9)ans = -1;
			else ans = 1;
			x -= 9;
		}
		if (ans != -1){
			if (x % 4 == 0){
				ans += x / 4;
			}
			else if (x % 2 == 0){
				if (x == 2)ans = -1;
				else ans += (x - 2) / 4;
			}
		}
	printf("%d\n", ans);
	}



	return 0;
}