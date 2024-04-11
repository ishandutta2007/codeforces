#include<cstdio>
const int N=300002;
int n,m,a[N],b[N],l,r,mid,i;
bool check(int x){
	for(i=1;i<=n;i++){
		if(a[i]>=b[i-1]){
			if(a[i]+x>=m&&(a[i]+x)%m>=b[i-1])
				b[i]=b[i-1];
			else
				b[i]=a[i];
		}
		else{
			if(a[i]+x>=b[i-1])
				b[i]=b[i-1];
			else
				return 0;
		}
				
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	l=0;r=m;
	while(l<r){
		mid=l+r>>1;
		if(check(mid))
			r=mid;
		else
			l=mid+1;
	}	
	printf("%d\n",r);
}