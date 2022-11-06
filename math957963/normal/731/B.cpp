#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int n = 0;
	int a[200001];
	int s = 0;
	int x = 0;
	for (int i = 0; i < 200001; i++){
		a[i] = NULL;
	}
		scanf("%d",&n);
		for (int i = 0; i < n; i++){
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n-1; i++){
			if (a[i] < 0) s = 1;
			x = a[i] % 2;
			if (x !=0){
				a[i + 1]--;
			}
		}
		x = a[n-1] % 2;
		if (x != 0) s = 1;

		if (s==1)printf("NO\n");
		else printf("YES\n");
	return 0;
}