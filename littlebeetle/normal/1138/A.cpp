#include<cstdio>
const int N=100002;
int n,i,a[N],l[N],r[N],s;
int min(int x,int y){
	return x<y?x:y;
}
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++)
		if(a[i]==a[i-1])
			l[i]=l[i-1]+1;
		else
			l[i]=1;
	for(i=n;i;i--)
		if(a[i]==a[i+1])
			r[i]=r[i+1]+1;
		else
			r[i]=1;
	for(i=1;i<n;i++)
		if(a[i]!=a[i+1])
			s=max(s,min(l[i],r[i+1]));
	printf("%d",s*2);
	return 0;
}