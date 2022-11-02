#include<cstdio>
const int N=300002;
int T,n,a[N],i,p,s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		p=1<<30;
		s=0;
		for(i=1;i<=n;i++)
		scanf("%d",a+i);
		for(i=n;i;i--){
			if(p<a[i])
				s++;
			else
				p=a[i];
		}
		printf("%d\n",s);
	}
}