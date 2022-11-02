#include<cstdio>
const int N=1000002;
int n,a,s[N],u[N],v[N],i,l,r,p,o;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		s[a]++;
		if(!u[a])
			u[a]=i;
		v[a]=i;
	}
	for(i=1;i<N;i++)
		if(s[i]>p)
			p=s[i];
	o=1<<30;
	for(i=1;i<N;i++)
		if(s[i]==p&&v[i]-u[i]<o){
			l=u[i];
			r=v[i];
			o=r-l;
		}
	printf("%d %d\n",l,r);
	return 0;
}