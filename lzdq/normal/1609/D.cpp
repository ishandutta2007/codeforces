#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1005;
int n,d,pre[MAXN],cnt;
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
int siz[MAXN],m,a[MAXN];
int ans;
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; i++)
		pre[i]=i;
	for(int _=1; _<=d; _++){
		int x,y;
		scanf("%d%d",&x,&y);
		x=fnd(x),y=fnd(y);
		if(x==y) cnt++;
		else pre[x]=y;
		for(int i=1; i<=n; i++)
			siz[i]=0;
		for(int i=1; i<=n; i++)
			++siz[fnd(i)];
		m=0;
		for(int i=1; i<=n; i++)
			if(pre[i]==i) a[++m]=siz[i];
		sort(a+1,a+m+1);
		ans=-1;
		for(int i=m; i; i--){
			if(m-i>cnt) break;
			ans+=a[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}