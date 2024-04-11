#include<cstdio>
const int N=200002;
int n,i,j,k,a[N],l[N],r[N];
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&n);
	k=-1<<30;
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]==0)
			k=i;
		l[i]=i-k;
	}
	k=1<<30;
	for(i=n;i>=1;i--){
		if(a[i]==0)
			k=i;
		r[i]=k-i;
	}
	for(i=1;i<=n;i++)
		printf("%d ",min(l[i],r[i]));
}