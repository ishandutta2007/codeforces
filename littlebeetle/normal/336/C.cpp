#include<cstdio>
const int N=100002;
int n,a[N],i,k,p,s;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(k=30;k>=0;k--){
		p=((1<<30)-1)*2+1;
		s=0;
		for(i=1;i<=n;i++)
			if(a[i]>>k&1)
				p&=a[i],s++;
		if(p%(1<<k)==0){
			printf("%d\n",s);
			for(i=1;i<=n;i++)
				if(a[i]>>k&1)
					printf("%d ",a[i]);
			return 0;
		}
	}
}