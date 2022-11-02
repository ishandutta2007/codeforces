#include<cstdio>
const int N=1000002;
char s[N];
int k,n,sum[N],pre[N],nxt[N],i,l,r;
long long ans;
int main(){
	scanf("%d%s",&k,s+1);
	while(s[n+1])n++;
	pre[0]=0;
	for(i=1;i<=n;i++){
		pre[i]=pre[i-1];
		if(s[i-1]==49)
			pre[i]=i-1;
		sum[i]=sum[i-1]+(s[i]==49);
	}
	nxt[n+1]=n+1;
	for(i=n;i;i--){
		nxt[i]=nxt[i+1];
		if(s[i+1]==49)
			nxt[i]=i+1;
	}
	if(sum[n]<k){
		printf("0");
		return 0;
	}
	s[n+1]=49;
	pre[n+1]=pre[n];
	if(s[n]==49)
		pre[n+1]=n;
	if(k==0){
		for(i=1;i<=n+1;i++)
			if(s[i]==49)
				ans+=1ll*(i-pre[i])*(i-pre[i]-1)/2;
		printf("%lld",ans);
		//while(1);
		return 0;
	}
	l=r=0;
	for(i=1;i+k-1<=sum[n];i++){
		while(sum[l]!=i)l++;
		while(sum[r]!=i+k-1)r++;
			//printf("%d %d\n",l,r);
		ans+=1ll*(l-pre[l])*(nxt[r]-r);
	}
	printf("%lld",ans);
	//while(1);
}