#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int T,n,m,k,a[N],b[N],l1,l2;pair<int,ll> c[N],d[N];
void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
	l1=l2=0;
	for(int i=1;i<=n;i++){
		int awa=1;
		while(a[i]%k==0)a[i]/=k,awa*=k;
		if(a[i]==c[l1].first)c[l1].second+=awa;
		else c[++l1]=make_pair(a[i],awa);
	}
	for(int i=1;i<=m;i++){
		int awa=1;
		while(b[i]%k==0)b[i]/=k,awa*=k;
		if(b[i]==d[l2].first)d[l2].second+=awa;
		else d[++l2]=make_pair(b[i],awa);
	}
	if(l1!=l2){printf("No\n");return;}
	for(int i=1;i<=l1;i++)if(c[i]!=d[i]){printf("No\n");return;}
	printf("Yes\n");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}