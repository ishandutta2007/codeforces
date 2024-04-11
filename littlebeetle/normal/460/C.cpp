#include<cstdio>
const int N=100002;
int n,m,w,a[N],i,j,k,l,r,mid;
long long s,c[N];
int main(){
	scanf("%d%d%d",&n,&m,&w);
	l=1<<30;
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]<l)l=a[i];
		if(a[i]+m>r)r=a[i]+m;
	}
	while(l<r){
		mid=l+r+1>>1;
		for(i=1;i<=n;i++)
			c[i]=0;
		s=0;
		for(i=1;i<=n;i++){
			c[i]+=c[i-1];
			if(a[i]+c[i]<mid){
				k=mid-(a[i]+c[i]);
				s+=k;
				c[i]+=k;
				if(i+w<=n)
					c[i+w]-=k;
			}
		}
		if(s<=m)
			l=mid;
		else
			r=mid-1;
	}
	printf("%d",l);
}