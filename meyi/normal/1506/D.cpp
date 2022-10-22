#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int a[maxn],b[maxn],m,n,t[maxn],t_case;
vector<pair<int,int> >tot;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		memset(t,0,sizeof t);
		tot.clear();
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i),b[i]=a[i];
		sort(b+1,b+n+1);
		ri ans=n,cnt=unique(b+1,b+n+1)-b-1;
		for(ri i=1;i<=n;++i)++t[lower_bound(b+1,b+cnt+1,a[i])-b];
		ri i=1;
		for(ri j=2;i<=cnt;++i){
			if(t[i]){
				for(j=max(i+1,j);t[i]&&j<=cnt;++j){
					ri d=min(t[i],t[j]);
					t[i]-=d,t[j]-=d,ans-=d*2;
					for(ri k=1;k<=d;++k)tot.push_back({i,j});
				}
				if(t[i])break;
			}
		}
		if(t[i])
			for(ri j=0;t[i]>1&&j<tot.size();++j)
				if(i!=tot[j].first&&i!=tot[j].second){
					ans-=2,t[i]-=2;
				}
		printf("%d\n",ans);
	}
	return 0;
}