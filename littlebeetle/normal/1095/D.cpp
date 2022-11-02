#include<cstdio>
const int N=200002;
int n,l[N],r[N],t[N],i,j,k;
int main(){
	scanf("%d",&n);
	if(n==3){
		printf("1 2 3");
		return 0;
	}
	for(i=1;i<=n;i++)
		scanf("%d %d",l+i,r+i);
	for(i=1;i<=n;i++){
		j=l[i];k=r[i];
		if(l[j]==k||r[j]==k)
			t[i]=j;
		else
			t[i]=k;
	}
	for(i=1;n;n--,i=t[i])
		printf("%d ",i);
}