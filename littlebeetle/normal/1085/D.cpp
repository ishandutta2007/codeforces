#include<cstdio>
const int N=100002;
int n,i,a,b,d[N],p,s;
int main(){
	scanf("%d%d",&n,&s);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		d[a]++;d[b]++;
	}
	for(i=1;i<=n;i++)
		if(d[i]==1)
			p++;
	printf("%.7lf",1.0*s/p*2);
}