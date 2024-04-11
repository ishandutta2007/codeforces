#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int T,n,a[N],id[N],b[N],ans[N],cnt[N];
bool cmp(int x,int y){return a[x]<a[y];}
void solve(){
	scanf("%d",&n),fill(cnt,cnt+n+1,0);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt[a[i]]++,id[i]=i;
	sort(id+1,id+n+1,cmp);int t=*max_element(cnt+1,cnt+n+1);
	for(int i=1;i<=n;i++)b[(i+t-1)%n+1]=a[id[i]];
	for(int i=1;i<=n;i++)ans[id[i]]=b[i];
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);printf("\n");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}