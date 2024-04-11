#include<cstdio>

using namespace std;

int a[1001],ans[1001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i;i--)
		a[i]-=a[i-1];
	for(int k=1;k<=n;k++){
		for(int i=k+1;i<=n;i++)
			if(a[i]!=a[i-k])
				goto ed;
		ans[++ans[0]]=k;
		ed:;
	}
	printf("%d\n",ans[0]);
	for(int i=1;i<=ans[0];i++)
		printf("%d%c",ans[i],i==ans[0]?'\n':' ');
}