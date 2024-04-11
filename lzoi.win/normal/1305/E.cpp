#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=5005;
int n,m;
int calc(int l,int r){
	int t=r-l*2;
	if(t&1) return (t+1>>1)*(t+1>>1);
	return (t>>1)*(t/2+1);
}
int ans[MAXN];
int main() {
	scanf("%d%d",&n,&m);
	bool flag=1;
	if(calc(1,n)<m) {
		puts("-1");
		return 0;
	}
	int cnt=0;
	for(int i=1; i<=n&&m>=(i-1>>1); i++){
		ans[++cnt]=i;
		m-=i-1>>1;
	}
	if(m){
		cnt++;
		ans[cnt]=ans[cnt-2*m]+ans[cnt-1];
	}
	if(n>cnt){
		ans[++cnt]=1e9;
		while(cnt<n) {
			cnt++;
			ans[cnt]=ans[cnt-1]-n;
		}
	}
	sort(ans+1,ans+n+1);
	for(int i=1; i<=n; i++)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}