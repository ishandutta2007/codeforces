#include<cstdio>
const int N=100020,INF=2e9+233;
int n,i,x[N],h[N],s;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d%d",x+i,h+i);
	x[0]=-INF/2;
	x[n+1]=INF;
	for(i=1;i<=n;i++)
		if(x[i]-x[i-1]>h[i])
			s++;
		else
			if(x[i+1]-x[i]>h[i])
				s++,x[i]+=h[i];
	printf("%d",s);
}