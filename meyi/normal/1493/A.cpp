#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int k,n,t;
queue<int>q;
bool vis[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(ri i=k+1;i<=n;++i)q.push(i);
		memset(vis,0,sizeof vis);
		vis[0]=true;
		for(ri i=k-1;i;--i)
			if(!vis[k-i]){
				q.push(i);
				for(ri j=k;j>=i;--j)vis[j]|=vis[j-i];
			}
		printf("%d\n",q.size());
		while(q.size())printf("%d ",q.front()),q.pop();
		printf("\n");
	}
}