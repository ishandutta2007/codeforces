#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=105;
int n;
int a[MAXN],b[MAXN],t[MAXN];
bool ans;
int main(){
	int q; scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		int l,r;
		scanf("%d",&l);
		r=l;
		ans=1;
		for(int i=1; i<=n; i++){
			scanf("%d%d%d",t+i,a+i,b+i);
			if(!ans) continue;
			l-=t[i]-t[i-1];
			r+=t[i]-t[i-1];
			if(r<a[i]||l>b[i]) ans=0;
			l=max(l,a[i]);
			r=min(r,b[i]);
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}