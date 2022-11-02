#include<cstdio>
const int N=200002;
int T,n,i,r,k,pre[N],ans;
char s[N];
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%s",s+1);
		n=0;
		while(s[n+1])n++;
		for(i=1;i<=n;i++){
			pre[i]=pre[i-1];
			if(s[i-1]==49)
				pre[i]=i-1;
		}
		for(r=1;r<=n;r++){
			k=0;
			for(i=r;i&&r-i<=20;i--){
				if(s[i]==49)
					k|=1<<(r-i);
				if(k==r-i+1)
					ans++;
			}
			if(k>=r-i+1&&r-pre[i+1]>=k)
			ans++;
		}
		printf("%d\n",ans);
	}
}