#include<cstdio>
const int N=100002;
int n,a[N],i,s;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<n;i++){
		if(a[i]==1&&a[i+1]==2)
			s+=3;
		if(a[i]==1&&a[i+1]==3)
			s+=4;
		if(a[i]==2&&a[i+1]==1)
			s+=3;
		if(a[i]==3&&a[i+1]==1)
			s+=4;
		if(a[i]+a[i+1]==5){
			printf("Infinite");
			return 0;
		}
		if(a[i]==1&&a[i-1]==3&&a[i+1]==2)
			s--;
	}
	printf("Finite\n%d",s);
	//while(1);
}