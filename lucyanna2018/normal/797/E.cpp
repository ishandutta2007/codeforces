#include<bits/stdc++.h>
#define ran 111111
const int magic = 300;
int n,a[ran];
int d[magic][ran];
int dp(int p,int k){
	if(p>n)return 0;
	int&res = d[k][p];
	if(res != 0)return res;
	return res = dp(p+a[p]+k,k)+1;
}
int sim(int p,int k){
	int s = 0;
	while(p <= n){
		p += a[p] + k;
		s++;
	}
	return s;
}
int main(){
	int q;
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	for(scanf("%d",&q); q--; ){
		int p,k;
		scanf("%d%d",&p,&k);
		if(k < magic){
			printf("%d\n",dp(p,k));
		}else
			printf("%d\n",sim(p,k));
	}
	return 0;
}