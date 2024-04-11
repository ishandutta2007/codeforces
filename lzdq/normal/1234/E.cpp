#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m;
int x[MAXN];
ll ans[MAXN];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",x+i);
		if(i==1) continue;
		int a=x[i-1],b=x[i];
		if(a==b) continue;
		if(a>b) swap(a,b);
		ans[1]+=b-a;
		ans[a]-=b-a;
		ans[a]+=b-1;
		ans[a+1]-=b-1;
		ans[a+1]+=b-a-1;
		ans[b]-=b-a-1;
		ans[b]+=a;
		ans[b+1]-=a;
		ans[b+1]+=b-a;
	}
	for(int i=1;i<=n;i++)
		ans[i]+=ans[i-1],printf("%I64d ",ans[i]);
	puts("");
	return 0;
}