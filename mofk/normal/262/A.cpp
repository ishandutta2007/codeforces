#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define MAX (int)1e5+5
#define f(i,n) for(i=1;i<=n;i++)
#define ff(i,a,b) for(i=a;i<=b;i++)
typedef long long ll;
using namespace std;
int main(void)
{
	int n,i,j,k,cnt=0,ans=0;
	char a[105][15];
	scanf("%d%d",&n,&k);
	f(i,n) {
		scanf("%s",&a[i]);
		ff(j,0,strlen(a[i])-1) if(a[i][j]=='4'||a[i][j]=='7') cnt++;
		if(cnt<=k) ans++;
		cnt=0;
	}
	printf("%d",ans);
}