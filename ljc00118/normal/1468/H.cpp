#include <cstdio>

int t,n,k,m,b[200010];
bool vis[200010];
int main(){
	scanf("%d",&t);
	for(int fd=1;fd<=t;fd++){
		scanf("%d%d%d",&n,&k,&m);
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=1;i<=m;i++)scanf("%d",b+i),vis[b[i]]=1;
		if((n-m)%(k-1)!=0){
			puts("NO");
			continue;
		}
		int cnt=0,tot=n-m;
		bool good=0;
		for(int i=1;i<=n;i++){
			if(!vis[i])++cnt;
			else{
				if(cnt>=((k-1)>>1)&&(tot-cnt)>=((k-1)>>1))good=1;
			}
		}
		if(good)puts("YES");
		else puts("NO");
	}
}