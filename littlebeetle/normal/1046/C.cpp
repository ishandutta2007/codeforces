#include<cstdio>
const int N=200002;
int n,d,i,j,s[N],p[N],o,sum;
int main(){
	scanf("%d%d",&n,&d);
	for(i=1;i<=n;i++)
		scanf("%d",s+i);
	for(i=1;i<=n;i++)
		scanf("%d",p+i);
	o=s[d]+p[1];
	j=2;
	for(i=d-1;i;i--){
		while(j<=n&&s[i]+p[j]>o)
			j++;
		if(j<=n)
			j++,sum++;
	}
	printf("%d",n-(sum+(n-d)));
}