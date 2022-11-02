#include<cstdio>
int n,a,cnt,t=1;
long long ans;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		if(a>=1)
			ans+=a-1;
		else
			if(a<=-1)
				ans+=-1-a,t*=-1;
			else
				cnt++;
	}
	if(cnt)
		printf("%I64d",ans+cnt);
	else
		if(t==-1)
			printf("%I64d",ans+2);
		else
			printf("%I64d",ans);
}