#include<cstdio>
#include<algorithm>
using namespace std;

int b[20000001],p[2000001],a[20000001];
int c[300001],z[20000001];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	for(int i=2;i<=20000000;i++){
		if(!b[i])p[++p[0]]=i,a[i]=i;
		for(int j=1;j<=p[0]&&i*p[j]<=20000000;j++){
			b[i*p[j]]=1;
			a[i*p[j]]=p[j];
			if(i%p[j]==0)break;
		}
	}
	int n;
	scanf("%d",&n);
	int o=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]),o=gcd(o,c[i]);
	for(int i=1;i<=n;i++){
		c[i]/=o;
		for(;c[i]!=1;){
			int aa=a[c[i]];
			z[aa]++;
			while(c[i]%aa==0)c[i]/=aa;
		}
	}
	int ans=n;
	for(int i=2;i<=20000000;i++)
		ans=min(ans,n-z[i]);
	printf("%d\n",ans==n?-1:ans);
}