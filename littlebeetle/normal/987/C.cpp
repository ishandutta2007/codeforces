#include<cstdio>
const int N=3003,Inf=1<<29;
int n,i,j,k,s[N],c[N],x,y,z;
int ans=Inf;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",s+i);
	for(j=1;j<=n;j++)
		scanf("%d",c+j);
	for(j=1;j<=n;j++){
		y=c[j];
		x=z=Inf;
		for(i=1;i<j;i++)
			if(s[i]<s[j]&&c[i]<x)
				x=c[i];
		for(k=j+1;k<=n;k++)
			if(s[k]>s[j]&&c[k]<z)
				z=c[k];
		if(ans>x+y+z)
			ans=x+y+z;
	}
	printf("%d",ans==Inf?-1:ans);
	//while(1);
}