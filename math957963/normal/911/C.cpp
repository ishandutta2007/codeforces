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
	int x, y, z;
	int c1 = 0;
	int c2 = 0;
	int c3 = 0;
	int c4 = 0;
	bool ans = false;

	scanf("%d %d %d", &x, &y, &z);
	if (x == 1)c1++;
	if (x == 2)c2++;
	if (x == 3)c3++;
	if (x == 4)c4++;
	if (y == 1)c1++;
	if (y == 2)c2++;
	if (y == 3)c3++;
	if (y == 4)c4++;
	if (z == 1)c1++;
	if (z == 2)c2++;
	if (z == 3)c3++;
	if (z == 4)c4++;


	if (c1 > 0)ans = true;
	else if (c2 > 1)ans = true;
	else if (c3 > 2)ans = true;
	else if (c2 > 0 && c4 > 1)ans = true;
	if (ans)printf("YES\n");
	else printf("NO\n");

	return 0;
}