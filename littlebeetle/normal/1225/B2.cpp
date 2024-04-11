#include<cstdio>
const int N=1000200;
int T,n,k,d,a[N],s[N],l,r,i,j,ans,sum;
void init(){
	scanf("%d%d%d",&n,&k,&d);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		s[a[i]]=0;
	}
	sum=0;
}
void work(){
	for(i=1;i<=d;i++){
		if(s[a[i]]==0)
			sum++;
		s[a[i]]++;
	}
	ans=sum;
	for(i=d+1;i<=n;i++){
		if(s[a[i]]==0)
			sum++;
		s[a[i]]++;
		if(s[a[i-d]]==1)
			sum--;
		s[a[i-d]]--;
		if(sum<ans)
			ans=sum;
	}
	printf("%d\n",ans);
}
int main(){
	scanf("%d",&T);
	while(T--){
		init();
		work();
	}
	//while(1);
	return 0;
}