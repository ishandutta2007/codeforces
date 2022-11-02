#include<cstdio>
const int N=10002;
int n,a,s[N],i,p[N];
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		s[a]++;
	}
	a=0;
	n=0;
	for(i=1;i<N;i++)
		if(s[i])
			s[i]--,p[++n]=i,a=i;
	for(i=a-1;i>0;i--)
		if(s[i])
			p[++n]=i;
	printf("%d\n",n);
	for(i=1;i<=n;i++)
		printf("%d ",p[i]);
}