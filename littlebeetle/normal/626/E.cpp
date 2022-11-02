#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200020;
typedef long long ll;
int n,i,a[N],ans,Len,l,r,mid;
ll s[N];
double x;
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
}
double Update(int r1,int r2,int id,int len){
	double sum=1.0*(a[id]+s[r1]-s[r1-len]+s[r2]-s[r2-len])/(len*2+1)-a[id];
	if(sum>x){
		x=sum;
		ans=id;
		Len=len;
	}
	return sum;
}
void Query(int l1,int r1,int l2,int r2,int p){
	l=1;r=min(r1-l1+1,r2-l2+1);
	if(r<=4){
		while(r)
			Update(r1,r2,p,r--);
		return;
	}
	while(l<r){
		mid=l+r>>1;
		if(Update(r1,r2,p,mid)>Update(r1,r2,p,mid+1))
			r=mid-1;
		else
			l=mid+2;
	}
	if(l==r){
		Update(r1,r2,p,l);
	}
}
void work(){
	ans=1;
	for(i=2;i<n;i++)
		Query(1,i-1,i+1,n,i);
	printf("%d\n",Len*2+1);
	for(i=ans-Len;i<=ans;i++)
		printf("%d ",a[i]);
	for(i=n-Len+1;i<=n;i++)
		printf("%d ",a[i]);
}
int main(){
	init();
	work();
	return 0;
}