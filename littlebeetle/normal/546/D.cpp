#include<cstdio>
const int N=5000002;
typedef long long ll;
int n,a[N],i,j,k,x,y,T;
ll s[N];
bool f[N];
int main(){
	for(i=2;i<N;i++){
		if(!f[i])a[k++]=i,s[i]=1;
		for(j=0;(!j||i%a[j-1])&&i*a[j]<N;j++)
			f[i*a[j]]=1,s[i*a[j]]=s[i]+1;
		s[i]+=s[i-1];
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&x,&y);
		printf("%lld\n",s[x]-s[y]);
	}
}