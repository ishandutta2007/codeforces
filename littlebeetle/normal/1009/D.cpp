#include<cstdio>
const int N=100002;
int n,m,s,i,j,u[N],v[N];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n&&s<m;i++)
		for(j=i+1;j<=n&&s<m;j++)
			if(gcd(i,j)==1)
				s++,u[s]=i,v[s]=j;
	if(s<m||m<n-1)
		printf("Impossible");
	else{
		printf("Possible\n");
		for(i=1;i<=m;i++)
			printf("%d %d\n",u[i],v[i]);
	}
}