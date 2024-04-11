#include<cstdio>
#include<algorithm>
using namespace std;

int a[101],b[101],c[101],d[101],e[101],f[101];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]]=1;
	}
	int p=0,q=0,ans=0;
	for(int i=1;i<=n;i++)
		if(!b[i])(i&1)==0?++p:++q;
	for(int i=1;i<n;i++)
		if(a[i]&&a[i+1]&&((a[i]^a[i+1])&1)!=0)
			ans++;
	if(p+q==n){
		printf("%d\n",n==1?0:1);
		return 0;
	}
	for(int i=1;i<=n;){
		int j=i;
		while(j<=n&&a[j]==0)j++;
		if(i<j){
			if((i==1||(a[i-1]&1)==0)&&(j==n+1||(a[j]&1)==0)){
				if(i==1||j==n+1)e[++e[0]]=j-i;
				else c[++c[0]]=j-i;
			}
			else if((i==1||(a[i-1]&1)==1)&&(j==n+1||(a[j]&1)==1)){
				if(i==1||j==n+1)f[++f[0]]=j-i;
				else d[++d[0]]=j-i;
			}
			else ans++;
		}
		i=j+1;
	}
	sort(c+1,c+c[0]+1);
	sort(d+1,d+d[0]+1);
	ans+=c[0]*2+d[0]*2+e[0]+f[0];
	for(int i=1;i<=c[0];i++)
		if(p>=c[i])p-=c[i],ans-=2;
	for(int i=1;i<=e[0];i++)
		if(p>=e[i])p-=e[i],ans--;
	for(int i=1;i<=d[0];i++)
		if(q>=d[i])q-=d[i],ans-=2;
	for(int i=1;i<=f[0];i++)
		if(q>=f[i])q-=f[i],ans--;
	printf("%d\n",ans);
}