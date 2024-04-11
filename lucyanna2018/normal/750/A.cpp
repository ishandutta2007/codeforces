#include<bits/stdc++.h>
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	k=(240-k)/5;
	int res = n;
	for(int i=1; i<=n; i++){
		if(k<i){
			res = i-1;
			break;
		}
		k-=i;
	}
	printf("%d\n",res);
	return 0;
}