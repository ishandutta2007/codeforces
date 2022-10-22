#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
int n,m;
int p[MAXN],c[MAXN];
int ans;
int main(){
	int t; scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=1;
		for(int i=1; i<=n; i++){
			scanf("%d%d",p+i,c+i);
			if(i>1&&p[i]<p[i-1]||c[i]<c[i-1]||p[i]-p[i-1]<c[i]-c[i-1])
				ans=0;
		}
		if(ans) puts("YES");
		else puts("NO");
	}
	return 0;
}