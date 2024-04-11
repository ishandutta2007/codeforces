#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=110;
int a[maxn],d[maxn],n,t;
void dfs(int l,int r){
	if(l>r)return;
	int m=0,p;
	for(ri i=l;i<=r;++i){
		++d[i];
		if(a[i]>m)m=a[i],p=i;
	}
	dfs(l,p-1),dfs(p+1,r);
}
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		memset(d,-1,sizeof d);
		dfs(1,n);
		for(ri i=1;i<=n;++i)printf("%d ",d[i]);
		printf("\n");
	}
}