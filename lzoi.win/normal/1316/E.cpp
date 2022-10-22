#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
typedef long long ll;
const ll INF=1ll<<60;
int n,p,kk;
struct node{
	int a,s[7];
}a[MAXN];
bool operator <(node a,node b){
	return a.a>b.a;
}
ll f[MAXN][1<<7];
int main(){
	scanf("%d%d%d",&n,&p,&kk);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i].a);
	for(int i=1; i<=n; i++)
		for(int j=0; j<p; j++)
			scanf("%d",&a[i].s[j]);
	sort(a+1,a+n+1);
	for(int i=1;i<1<<p;i++) f[0][i]=-INF;
	for(int i=1; i<=n; i++){
		for(int j=0; j<1<<p; j++){
			int tot=0;
			f[i][j]=-INF;
			for(int k=0; k<p; k++){
				if(1<<k&j) tot++,f[i][j]=max(f[i][j],f[i-1][j^1<<k]+a[i].s[k]);
			}
			f[i][j]=max(f[i][j],f[i-1][j]+(i-tot-1<kk?a[i].a:0));
		}
	}
	printf("%I64d\n",f[n][(1<<p)-1]);
	return 0;
}