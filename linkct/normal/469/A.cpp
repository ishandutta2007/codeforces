#include <cstdio>

bool vis[105];
int n;

int main(){
	int i, x, p;
	scanf("%d%d", &n, &p);
	for(i = 1; i <= p; ++ i){
		scanf("%d", &x);
		vis[x] = true;
	}
	scanf("%d", &p);
	for(i = 1; i <= p; ++ i){
		scanf("%d", &x);
		vis[x] = true;
	}
	for(i = 1; i <= n; ++ i)
		if(!vis[i]){
			printf("Oh, my keyboard!\n");
			return 0;
		}
	printf("I become the guy.\n");
	return 0;
}