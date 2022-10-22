#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=110;
struct node{
	int v,x;
	inline bool operator<(const node &k)const{
		return v<k.v;
	}
};
vector<node>v;
int a,ans[maxn][maxn],len[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		memset(ans,0,sizeof ans);
		memset(len,0,sizeof len);
		v.clear();
		for(ri i=1;i<=n;++i){
			for(ri j=1;j<=m;++j){
				scanf("%d",&a);
				v.push_back({a,i});
			}
		}
		sort(v.begin(),v.end());
		for(ri i=0;i<m;++i)ans[v[i].x][i+1]=v[i].v;
		for(ri i=m;i<v.size();++i){
			++len[v[i].x];
			while(ans[v[i].x][len[v[i].x]])++len[v[i].x];
			ans[v[i].x][len[v[i].x]]=v[i].v;
		}
		for(ri i=1;i<=n;printf("\n"),++i)
			for(ri j=1;j<=m;++j)
				printf("%d ",ans[i][j]);
	}
	return 0;
}