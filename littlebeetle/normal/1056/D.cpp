#include<cstdio>
#include<algorithm>
const int N=100002;
int n,i,p[N],s[N];
int main(){
	scanf("%d",&n);
	for(i=2;i<=n;i++)
		scanf("%d",p+i);
	for(i=n;i;i--){
		if(!s[i])s[i]=1;
		s[p[i]]+=s[i];
	}
	std::sort(s+1,s+n+1);
	for(i=1;i<=n;i++)
		printf("%d ",s[i]);
}