#include<cstdio>
const int N=100002;
int n,m,i,a,b,c,x[N],s;
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		scanf("%d%d%d",&a,&b,&c);
		x[a]+=c;
		x[b]-=c;
	}
	for(i=1;i<=n;i++)
		s+=x[i]>0?x[i]:0;
	printf("%d",s);
}