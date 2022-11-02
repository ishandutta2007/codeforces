#include<cstdio>
const int N=102;
int n,a[N],s[N],i,f[N];
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=n;i;i--){
		s[i]=a[i]+s[i+1];
		f[i]=max(a[i]+s[i+1]-f[i+1],f[i+1]);
	}
	printf("%d %d",s[1]-f[1],f[1]);
}