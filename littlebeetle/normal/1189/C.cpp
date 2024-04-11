#include<cstdio>
const int N=100002;
int n,s[N],q,i,l,r;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",s+i),s[i]+=s[i-1];
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&l,&r);
		printf("%d\n",(s[r]-s[l-1])/10);
	}
	return 0;
}