#include<cstdio>
int n,i,a,s=1<<30;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&a),
		s=min(s,min(a/(i>1?i-1:1),a/(n>i?n-i:1)));
	printf("%d",s);
}