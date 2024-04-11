#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=105;
int n;
char s[MAXN];
int a[MAXN],b[MAXN];
int ans;
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	int sum=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='1') sum++;
	for(int i=1;i<=n;i++)
		scanf("%d%d",a+i,b+i);
	ans=sum;
	for(int t=1;t<=10000;t++){
		for(int i=1;i<=n;i++)
			if(t>=b[i]&&(t-b[i])%a[i]==0) sum+=(s[i]=='0'?1:-1),s[i]^=1;
		ans=max(ans,sum);
	}
	printf("%d\n",ans);
	return 0;
}