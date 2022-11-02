#include<cstdio>
const int N=100020;
int n,k,l,r,mid,i,j,a[N],b[N],s,f[N],u=-1<<30,v=1<<30;
int abs(int x){
	return x>0?x:-x;
}
int max(int x,int y){
	return x>y?x:y;
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]>u)u=a[i];
		if(a[i]<v)v=a[i];
	}
	l=0;r=u-v;
	while(l<r){
		mid=(1ll*l+r)/2;
		for(i=0;i<=n;i++)
			f[i]=0;
		s=0;
		for(i=1;i<=n;i++){
			f[i]=1;
			for(j=1;j<i;j++)
				if(abs(a[i]-a[j])<=1ll*mid*abs(i-j))
					f[i]=max(f[i],f[j]+1);
			s=max(s,f[i]);
		}
		if(s+k>=n)
			r=mid;
		else
			l=mid+1;
	}
	printf("%d",r);
}