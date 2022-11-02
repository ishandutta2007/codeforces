#include<cstdio>
const int N=100002;
int T,x,y,n,i,cnt;
char s[N],t[N];
int main(){
	scanf("%d",&T);
	while(T--){
		x=y=0;cnt=0;
		scanf("%d%s%s",&n,s+1,t+1);
		for(i=1;i<=n;i++)
			if(s[i]!=t[i]){
				cnt++;
				if(x==0)
					x=s[i]*100+t[i];
				else
					y=s[i]*100+t[i];
			}
		if(cnt==0||(cnt==2&&x==y))
			printf("Yes\n");
		else
			printf("No\n");
	}
}