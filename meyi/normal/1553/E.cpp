#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline void ckmax(int &x,const int &y){if(x<y)x=y;}
template<class T>inline void ckmin(int &x,const int &y){if(x>y)x=y;}
int a[maxn],cnt[maxn],fa[maxn],m,n,t_case;
int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			++cnt[(i-a[i]+n)%n];
		}
		vector<int>ans;
		for(ri i=0;i<n;++i)
			if(cnt[i]>=n-2*m){
				for(ri j=1;j<=n;++j)fa[j]=j;
				for(ri j=1;j<=n;++j){
					ri fx=find(a[j]),fy=find((j-i+n-1)%n+1);
					if(fx!=fy)fa[fx]=fy;
				}
				ri tmp=0;
				for(ri j=1;j<=n;++j)
					if(find(j)==j)
						++tmp;
				if(n-tmp<=m)ans.push_back(i);
			}
		printf("%u",ans.size());
		for(auto i:ans)printf(" %d",i);
		printf("\n");
		for(ri i=1;i<=n;++i)cnt[i]=0;
	}
}