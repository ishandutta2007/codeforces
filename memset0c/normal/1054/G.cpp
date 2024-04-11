#include<bits/stdc++.h>
const int N=2e3+10;
int Test,n,m,siz[N],cnt[N][N];
char str[N];
bool exist[N];
std::bitset<N> a[N];
std::vector<std::pair<int,int>> ans,q;
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	scanf("%d",&Test);
	for(int Case=1;Case<=Test;Case++){
		scanf("%d%d",&n,&m),q.clear(),ans.clear();
		for(int i=0;i<n;i++)a[i].reset();
		for(int i=0;i<m;i++){
			scanf("%s",str),siz[i]=0;
			for(int j=0;j<n;j++)if(str[j]=='1')a[j].set(i),siz[i]++;
		}
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<m;j++)putchar('0'+a[i][j]);
		// 	putchar('\n');
		// }
		// for(int i=0;i<m;i++)printf("%d%c",siz[i]," \n"[i+1==m]);
		for(int i=0;i<n;i++){
			int all=a[i].count();
			for(int j=0;j<n;j++)if(i!=j){
				cnt[i][j]=all-(a[i]&a[j]).count();
				if(!cnt[i][j])q.push_back({i,j});
			}
		}
		for(int i=0;i<n;i++)exist[i]=true;
		for(int k=0;k<m;k++)if(siz[k]==1)
			for(int i=0;i<n;i++)if(a[i][k]&&exist[i]){
				// printf("del %d => %d\n",k+1,i+1);
				for(int j=0;j<n;j++)if(cnt[i][j]&&!(--cnt[i][j]))
					q.push_back({i,j});
			}
		// for(int i=0;i<n;i++)
		// 	for(int j=0;j<n;j++)
		// 		printf("%d%c",cnt[i][j]," \n"[j+1==n]);
		for(int u,v;ans.size()<n-1&&q.size();){
			std::tie(u,v)=q.back(),q.pop_back();
			if(!exist[u]||!exist[v])continue;
			for(int k=0;k<m;k++)if(a[u][k]&&(--siz[k])==1)
				for(int i=0;i<n;i++)if(a[i][k]&&exist[i]&&i!=u){
					// printf("del %d => %d\n",k+1,i+1);
					for(int j=0;j<n;j++)if(cnt[i][j]&&!(--cnt[i][j]))
						q.push_back({i,j});
				}
			ans.push_back({u,v});
			exist[u]=false;
			// printf("%d %d\n",u+1,v+1);
			// for(int i=0;i<n;i++)if(exist[i]){
			// 	for(int j=0;j<n;j++)if(exist[j]){
			// 		printf("cnt[%d][%d]=%d\n",i+1,j+1,cnt[i][j]);
			// 	}
			// }
		}
		if(ans.size()==n-1){
			puts("YES");
			for(const auto &it:ans)printf("%d %d\n",it.first+1,it.second+1);
		}else{
			puts("NO");
		}
	}
}