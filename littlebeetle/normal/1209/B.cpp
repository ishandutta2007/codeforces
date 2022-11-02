#include<cstdio>
const int N=102;
char s[102];
int n,i,ans,sum,Tim,p[102],a[102],b[102];
int main(){
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++)
		p[i]=s[i]-48,ans+=p[i];
	for(i=1;i<=n;i++)
		scanf("%d%d",a+i,b+i);
	for(Tim=1;Tim<=10000;Tim++){
		sum=0;
		for(i=1;i<=n;i++){
			if(Tim>=b[i]&&(Tim-b[i])%a[i]==0)
				p[i]^=1;
			sum+=p[i];
		}
		if(sum>ans)
			ans=sum;
	}
	printf("%d",ans);
	
}