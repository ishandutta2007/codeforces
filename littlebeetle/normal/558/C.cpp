#include<cstdio>
const int N=100002;
int n,i,a[N],p,j,x,k,ans=1<<30,s,o,l;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		while(a[i]>>p)
			p++;
	}
	while(p--){
		j=1<<p;
		k=(1<<p+1)-1;
		for(i=1;i<=n;i++){
			x=a[i];
			while(x<j)x<<=1;
			while(x>=(j<<1))x>>=1;
			k&=x;
		}
		s=0;
		for(i=1;i<=n;i++){
			l=k;
			x=a[i];
			while((l>x)&&(l^x)>x)l>>=1;
			while((x>l)&&(l^x)>l)x>>=1,s++;	
			while(x!=l)x>>=1,l>>=1,s++;
			while(x<k)x<<=1,s++;
		}
		if(s<ans)
			ans=s;
	}
	printf("%d",ans);
	return 0;
}