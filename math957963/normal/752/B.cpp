#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main(void){
	char a[10001];
	char b[10001];
	int x[27];
	int p;
	int q;
	int n;
	int c;
	int d;
	c = 0;
	d = 0;
	for (int i = 0; i < 27; i++)x[i] = 0;
	scanf("%s", a);
	scanf("%s", b);
	n = strlen(a);
	for (int i = 0; i < n; i++){
		p = a[i];
			q = b[i];
			p = p - 96;
			q = q - 96;
			if (x[p] != 0 || x[q] != 0){
				if (x[p] != q)d = 1;
				if (x[q] != p)d = 1;
			}
		else {
				x[p] = q;
				x[q] = p;
				if(p!=q)c++;
		}
	}
	if (d == 1)printf("-1\n");
	else {
		printf("%d\n", c);
		for (int i = 1; i < 27; i++){
			if (i < x[i]){
				printf("%c %c\n", i + 96, x[i] + 96);
			}
		}
	}
	return 0;
}