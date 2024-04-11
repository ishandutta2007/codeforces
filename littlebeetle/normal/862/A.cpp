#include<cstdio>
const int N=10002;
int n,x,a,i,s[N],ans;
int main(){
	scanf("%d%d",&n,&x);
	while(n--){
		scanf("%d",&a);
		s[a]++;
	}
	for(i=0;i<x;i++)
		if(!s[i])
			ans++;
	ans+=s[x];
	printf("%d\n",ans);
	//while(1);
}