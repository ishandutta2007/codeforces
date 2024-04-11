#include<cstdio>
const int N=1002;
int n,k,m,i,a,s[N],p;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		s[a]++;
	}
	m=(n+1)/2;
	for(i=1;i<=k;i++){
		m-=s[i]/2;
		p+=(s[i]/2)*2;
		s[i]%=2;
	}
	for(i=1;i<=k;i++)
		if(s[i]&&m)
			p++,m--;
	printf("%d",p);
}