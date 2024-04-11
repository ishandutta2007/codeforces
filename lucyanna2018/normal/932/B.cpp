#include<cstdio>
#include<cstring>
int f(int x){
	int r = 1;
	while(x){
		int w = x%10;
		if(w) r *= w;
		x /= 10;
	}
	return r;
}
int g[1011111];
int G(int x){
	if(g[x] != -1)return g[x];
	if(x < 10)return g[x] = x;
	return g[x] = G(f(x));
}
int c[1011111][10];
int main(){
	memset(g,-1,sizeof(g));
	for(int i=1; i<=1000000; i++){
		G(i);
		memcpy(c[i],c[i-1],sizeof(int)*10);
		c[i][g[i]] ++;
	}
	int q,l,r,k;
	for(scanf("%d",&q); q--;){
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",c[r][k] - c[l-1][k]);
	}
	return 0;
}