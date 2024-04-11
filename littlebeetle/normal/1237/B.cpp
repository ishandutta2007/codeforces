#include<cstdio>
const int N=500002;
int n,a[N],b[N],id[N],i,j,s,x,c[N],ans;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++)
		scanf("%d",b+i),id[b[i]]=i;
	for(i=1;i<=n;i++){
		s=0;
		for(x=id[a[i]];x<=n;x+=x&-x)
			s+=c[x];
		if(s)
			ans++;
		for(x=id[a[i]];x;x-=x&-x)
			c[x]++;
	}
	printf("%d",ans);
	//while(1);
}