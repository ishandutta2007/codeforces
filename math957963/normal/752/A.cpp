#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main(void){
	int n;
	int m;
	int x;
	int a;
	int b;
	scanf("%d %d %d", &n, &m,&x);
	x--;
	a = x / (2 * m);
	a++;
	x = x % (2 * m);
	b = x / 2;
	b++;
	x = x % 2;
	if (x == 0)printf("%d %d L\n",a,b);
	else printf("%d %d R\n",a,b);
	return 0;
}