#include<cstdio>
const int N=100002;
int n,m,i,a[N],q[N],s,e;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),q[i]=i;
	s=1;e=n;
	while(s<e){
		a[q[s]]-=m;
		if(a[q[s]]<=0)
			s++;
		else
			q[++e]=q[s++];
	}
	printf("%d",q[s]);
	//while(1);
}