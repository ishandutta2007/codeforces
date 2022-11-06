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

int main(){
	int n, k;
	int x, y, z;
	scanf("%d %d %d %d", &n, &k,&x,&y);
	if (x == 1){
		if (y == n){
			printf("0\n");
		}
		else{
			z = k - y;
			if (z < 0)z = -z;
			printf("%d\n", z+1);
		}
	}
	else{
		if (y == n){
			z = k - x;
			if (z < 0)z = -z;
			printf("%d\n", z+1);
		}
		else{
			z = k - y;
			n = k - x;
			if (z < 0)z = -z;
			if (n < 0)n = -n;
			if (n < z)z = n;
			printf("%d\n", z + y - x + 2);
		}
	}

	return 0;
}