#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
bool vis[maxn];
int a[maxn],id[maxn],m,n,tmp,t_case;
ll sum;
inline bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			id[i]=i;
			vis[i]=false;
		}
		sort(id+1,id+n+1,cmp);
		sum=0,tmp=n-1;
		for(ri i=1;i<=n;++i){
			if(a[id[i]]>=m)break;
			if(vis[id[i]])continue;
			vis[id[i]]=true;
			ri l=id[i]-1,r=id[i]+1;
			while(l>0&&a[l]%a[id[i]]==0){
				--tmp,sum+=a[id[i]];
				if(vis[l])break;
				vis[l]=true;
				--l;
			}
			while(r<=n&&a[r]%a[id[i]]==0){
				--tmp,sum+=a[id[i]];
				if(vis[r])break;
				vis[r]=true;
				++r;
			}
		}
		printf("%lld\n",sum+1ll*tmp*m);
	}
	return 0;
}