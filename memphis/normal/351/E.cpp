#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define ll long long
#define N 2005
#define eps 1e-5
//#define M
using namespace std;

int n,a[N];

int main(){
	scanf("%d",&n);
	rep(i,1,n) scanf("%d",a+i);
	rep(i,1,n) if(a[i]<0)a[i]*=-1;
	rep(i,1,n){
		int sum1=0,sum2=0;
		rep(j,1,i-1){
			if(a[j]>a[i])++sum1;
			if(a[j]>-a[i])++sum2;
		}
		rep(j,i+1,n){
			if(a[j]<a[i])++sum1;
			if(a[i]<-a[i])++sum2;
		}
		if(sum2<sum1)a[i]*=-1;
	}
	int ans=0;
	rep(i,1,n) rep(j,1,i-1) if(a[j]>a[i])++ans;
	printf("%d\n",ans);
	//for(;;);
}