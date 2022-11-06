#include<bits/stdc++.h>
#define ll long long
#define inf 1000000000000000000ll
#define N 5005
using namespace std;

int n,m,sum,a[N],q[N]; ll dp[N][N],s[N];
struct node{ int x,y; }b[N];
bool cmp(node u,node v){ return u.x<v.x; }
int main(){
	scanf("%d%d",&n,&m);
	int i,j,head,tail;
	for (i=1; i<=n; i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (i=1; i<=m; i++){
		scanf("%d%d",&b[i].x,&b[i].y);
		sum+=b[i].y;
	}
	if (sum<n){ puts("-1"); return 0; }
	sort(b+1,b+m+1,cmp);
	for (i=1; i<=n; i++) dp[0][i]=inf;
	for (i=1; i<=m; i++){
		for (j=1; j<=n; j++) s[j]=s[j-1]+abs(b[i].x-a[j]);
		head=1; tail=0;
		for (j=0; j<=n; j++){
			if (head<=tail && q[head]<j-b[i].y) head++;
			while (head<=tail && dp[i-1][j]-s[j]<=dp[i-1][q[tail]]-s[q[tail]]) tail--;
			q[++tail]=j;
			if (head<=tail) dp[i][j]=dp[i-1][q[head]]-s[q[head]]+s[j];
				else dp[i][j]=inf;
		}
	}
	printf("%lld\n",dp[m][n]);
	return 0;
}