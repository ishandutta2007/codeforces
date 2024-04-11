#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],fa[maxn],m,n,t_case;
bool vis[maxn];
inline int find(int k){
	if(!vis[k])return k;
	if(fa[k])return fa[k]=find(fa[k]);
	return fa[k]=find(k-1);
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&a[1]);
		ri lst=1;
		memset(vis,0,sizeof vis);
		printf("%d ",a[1]);
		vis[a[1]]=true;
		for(ri i=2,cnt=1;i<=n;++i){
			scanf("%d",a+i);
			if(a[i]!=a[lst])printf("%d ",a[i]),vis[a[i]]=true,lst=i;
			else{
				while(vis[cnt])++cnt;
				printf("%d ",cnt);
				vis[cnt]=true;
			}
		}
		puts("");
		lst=1;
		memset(vis,0,sizeof vis);
		printf("%d ",a[1]);
		vis[a[1]]=true;
		memset(fa,0,sizeof fa);
		for(ri i=2,cnt=a[1];i<=n;++i){
			if(a[i]!=a[lst])printf("%d ",a[i]),cnt=a[i],vis[a[i]]=true,lst=i;
			else{
				cnt=find(cnt);
				printf("%d ",cnt);
				vis[cnt]=true;
			}
		}
		puts("");
	}
	return 0;
}