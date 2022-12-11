#include<cstdio>
#include<algorithm>
using namespace std;
int a[400001],b[400001];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	m*=8;
	m/=n;
	if(m>=30){
		printf("%d\n",0);
		return 0;
	}
	int w=1<<m;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(i==1||a[i]!=a[i-1])b[i]=1;
		b[i]+=b[i-1];
	}
	int ans=0;
	for(int i=1,j=1;i<=n;i++){
		int z=lower_bound(b+1,b+n+1,b[i]+w)-b;
		ans=max(ans,z-i);
	}
	printf("%d\n",n-ans);
}