#include<stdio.h>
int val[11111];
int main(){
	int n,q;
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++)
		scanf("%d",&val[i]);
	while(q--){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		int cnt = 0;
		for(int i=l; i<=r; i++)
			if(val[i] < val[x])
				cnt ++;
		puts(cnt + l == x ? "Yes" : "No");
	}
	return 0;
}