#include<cstdio>
const int N=500002;
int n,i,x,s,ans;
bool f[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=2*n;i++){
		scanf("%d",&x);
		if(!f[x])
			s++,f[x]=1;
		else
			s--,f[x]=0;
		if(s>ans)
			ans=s;
	}
	printf("%d",ans);
	//while(1);
}