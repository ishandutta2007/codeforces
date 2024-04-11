#include<cstdio>
#include<algorithm>
using namespace std;
const int N=100002;
int n,h,i,a[N],d[N];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int work1(){
	return a[d[n]]+a[d[n-1]]-a[d[1]]-a[d[2]];
}
int work2(){
	int x=min(a[d[1]]+a[d[2]]+h,a[d[2]]+a[d[3]]);
	int y=max(a[d[1]]+a[d[n]]+h,a[d[n]]+a[d[n-1]]);
	return y-x;
}
int main(){
	scanf("%d%d",&n,&h);
	if(n==2){
		printf("0\n1 1");
		return 0;
	}
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		d[i]=i;
	}
	sort(d+1,d+n+1,cmp);
	if(work1()<work2()){
		printf("%d\n",work1());
		for(i=1;i<=n;i++)
			printf("1 ");
	}
	else{
		printf("%d\n",work2());
		for(i=1;i<=n;i++)
			printf("%d ",i==d[1]?1:2);
	}
}