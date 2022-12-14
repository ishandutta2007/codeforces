#include <cstdio>

inline int abs(int x){return x >= 0 ? x : -x;}
int main(){
	int a, b, s;
	scanf("%d%d%d", &a, &b, &s);
	int d = s - abs(a) - abs(b);
	if(d < 0 || d & 1) printf("No\n");
	else printf("Yes\n");
	return 0;
}