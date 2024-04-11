#include<cstdio>
int a1,a2,k1,k2,n;
int min(int x,int y){
	return x<y?x:y;
}
void work1(int a1,int a2,int k1,int k2,int n){
	n-=a1*(k1-1)+a2*(k2-1);
	if(n<0)
		printf("0 ");
	else
		printf("%d ",min(n,a1+a2));
}
void swap(int &x,int &y){
	int t=x;
	x=y;
	y=t;
}
void work2(int a1,int a2,int k1,int k2,int n){
	if(k1>k2){
		swap(a1,a2);
		swap(k1,k2);
	}
	if(k1*a1>n){
		printf("%d",n/k1);
		return;
	}
	n-=k1*a1;
	printf("%d",a1+min(a2,n/k2));
}
int main(){
	scanf("%d%d%d%d%d",&a1,&a2,&k1,&k2,&n);
	work1(a1,a2,k1,k2,n);
	work2(a1,a2,k1,k2,n);
}