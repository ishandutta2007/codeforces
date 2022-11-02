#include<cstdio>
const int N=100002;
int n,p[N],ans,i;
char s[N];
int main(){
	scanf("%d",&n);
	if(n>26){
		printf("-1");
		return 0;
	}
	scanf("%s",s+1);
	for(i=1;i<=n;i++){
		if(p[s[i]])
			ans++;
		p[s[i]]=1;
	}
	printf("%d",ans);
	//while(1);
}