#include<stdio.h>
int h[111],t[111],pre[111],nex[111];
int n,l;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d%d",&pre[i],&nex[i]);
		if(pre[i] == 0)
			h[l++] = i;
	}
	for(int j=0; j<l; j++){
		int x = h[j];
		while(nex[x] != 0)x = nex[x];
		t[j] = x;
	}
	for(int j=0; j<l-1; j++){
		pre[h[j+1]] = t[j];
		nex[t[j]] = h[j+1];
	}
	for(int i=1; i<=n; i++)
		printf("%d %d\n",pre[i],nex[i]);
	return 0;
}