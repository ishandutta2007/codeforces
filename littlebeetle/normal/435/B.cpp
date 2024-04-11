#include<cstdio>
const int N=100002;
int a[N],i,j,n,k,t,x;
char ch;
void swap(int &x,int &y){
	int t=x;x=y;y=t;
}
int main(){
	while((ch=getchar())>47)
		a[++n]=ch-48;
	a[0]=1000;
	scanf("%d",&k);
	for(i=1;i<=n;i++){
		t=i;
		for(j=i;j-i<=k&&j<=n;j++)
			if(a[j]>a[t])
				t=j;
		x=a[t];
		for(j=t;j>i;j--)
			a[j]=a[j-1];
		a[i]=x;
		k-=t-i;
	}
	for(i=1;i<=n;i++)
		printf("%d",a[i]);
}