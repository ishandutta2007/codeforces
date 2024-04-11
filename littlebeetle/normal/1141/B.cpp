#include<cstdio>
const int N=400002;
int n,i,j,a[N],ans;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		a[n+i]=a[i];
	}
	for(i=1;i<=n*2;i++){
		if(a[i]){
			for(j=i;a[j];j++);
			if(j-i>ans)
				ans=j-i;
			i=j;
		}
	}
	if(ans>n)
		ans=n;
	printf("%d",ans);
}