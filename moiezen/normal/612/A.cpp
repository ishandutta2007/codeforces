#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
int a[105]={0},t[105],f[105];
int n,p,q,i;
char s[105];
void print(int x){
	if(x==0) return;
	print(x-t[x]);
	for(i=x-t[x]+1;i<=x;i++) printf("%c",s[i]);
	printf("\n");
}
int main(){
	scanf("%d%d%d\n",&n,&p,&q);
	for(i=1;i<=n;i++) scanf("%c",&s[i]);
	a[0]=1;
	f[0]=0;
	for(i=1;i<=n;i++){
		if(i-p>=0){
			if(a[i-p]){
				a[i]=1;
				t[i]=p;
				f[i]=f[i-p]+1;
			}
		}
		if(i-q>=0){
			if(a[i-q]){
				a[i]=1;
				t[i]=q;
				f[i]=f[i-q]+1;
			}
		}
	}
	if(a[n]==0) printf("-1\n");
	else{
		printf("%d\n",f[n]);
		print(n);
	}
	return 0;
}