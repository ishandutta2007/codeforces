#include<cstdio>
const int N=100002;
int n,m,d,x[N],y[N],p[N],i,j,k,s,cnt;
int main(){
	scanf("%d%d%d",&n,&m,&d);
	d--;
	for(i=1;i<=m;i++)
		scanf("%d",x+i),s+=x[i];
	s=n-s;
	if(s>(m+1)*d){
		printf("NO");
		return 0;
	}
	printf("YES\n");
	for(i=1;i<=m+1;i++){
		if(s>=d)
			y[i]=d,s-=d;
		else
			y[i]=s,s=0;
	}
	for(i=1;i<=m;i++){
		cnt+=y[i];
		while(x[i]--){
			cnt++;
			p[cnt]=i;
		}
	}
	for(i=1;i<=n;i++)
		printf("%d ",p[i]);
}