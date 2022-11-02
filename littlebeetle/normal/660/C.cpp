#include<cstdio>
const int N=300002;
int n,a[N],k,i,l,r,s[N],ans,id;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++){
		s[i]=s[i-1];
		scanf("%d",a+i);
		if(a[i]==0)
			s[i]++;
	}
	s[i]=1<<30;
	for(l=r=0;l<n;l++){
		while(s[r+1]-s[l]<=k)
			r++;
		if(r-l>ans)
			ans=r-l,id=l;
	}
	printf("%d\n",ans);
	for(i=1;i<=ans;i++)
		a[id+i]=1;
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);
	//while(1);
}