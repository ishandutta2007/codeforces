#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int ans[maxn],cnt[maxn],m,n,slc[maxn],t_case;
vector<int>f[maxn];
inline bool cmp(int x,int y){
	return slc[x]<slc[y];
}
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		memset(ans,0,sizeof ans);
		memset(cnt,0,sizeof cnt);
		memset(slc,0,sizeof slc);
		bool flag=false;
		for(ri i=1;i<=m;++i){
			int a,l;
			scanf("%d",&l);
			f[i].clear();
			for(ri j=0;j<l;++j){
				scanf("%d",&a);
				f[i].push_back(a);
			}
			if(l==1){
				++cnt[a];
				if(cnt[a]>(m+1)/2)flag=true;
			}
		}
		if(flag){puts("NO");continue;}
		bool qwq=true;
		while(qwq){
			qwq=false;
			for(ri i=1;i<=m;++i){
				if(ans[i])continue;
				if(f[i].size()==1)ans[i]=f[i][0],++slc[f[i][0]];
			}
			for(ri i=1;i<=m;++i){
				if(ans[i])continue;
				vector<int>tmp;
				for(ri j=0;j<f[i].size();++j)
					if(slc[f[i][j]]==(m+1)/2)qwq=true;
					else tmp.push_back(f[i][j]);
				f[i]=tmp;
			}
		}
		for(ri i=1;i<=m;++i){
			if(ans[i])continue;
			//printf("%d %d %d\n",i,f[i][0],slc[f[i][0]]);
			sort(f[i].begin(),f[i].end(),cmp);
			++slc[f[i][0]];
			ans[i]=f[i][0];
		}
		for(ri i=1;i<=n;++i)
			if(slc[i]>(m+1)/2)
				flag=true;
		if(flag){puts("NO");continue;}
		puts("YES");
		for(ri i=1;i<=m;++i)printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}