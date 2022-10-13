#include<bits/stdc++.h>
bool f[111];
int n,k;
int main(){
	scanf("%d%d",&n,&k);
	int now = 1,x;
	for(int j=0; j<k; j++){
		scanf("%d",&x);
		x %= (n-j);
		while(x){
			++now;
			if(now == n+1)now = 1;
			if(f[now])continue;
			x--;
		}
		printf("%d%c",now,j<k-1?' ':'\n');
		f[now] = true;
		if(j == k-1)break;
		while(f[now]){
			++now;
			if(now == n+1)now = 1;
		}
	}
	return 0;
}