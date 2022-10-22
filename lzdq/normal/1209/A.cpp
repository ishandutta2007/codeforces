#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=105;
int n,ans;
int a[MAXN];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(!a[i]) continue;
		for(int j=i+1;j<=n;j++)
			if(a[j]&&a[j]%a[i]==0) a[j]=0;
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}