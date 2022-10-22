#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int d[4][2]={{-1,0},{0,-1},{1,0},{0,1}},maxm=25e4+10,maxn=510;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int ans[maxm],m,n;
char s[maxn][maxn];
vector<int>e[maxm];
inline void addedge(int fr,int to){
	e[fr].push_back(to);
	e[to].push_back(fr);
}
inline int idx(int x,int y){
	return (x-1)*m+y;
}
void dfs(int p){
	for(auto i:e[p])
		if(!ans[i])ans[i]=5-ans[p],dfs(i);
		else if(ans[i]!=5-ans[p])puts("NO"),exit(0);
}
signed main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=m;++j)
			if(s[i][j]=='X'){
				vector<int>tmp;
				for(ri k=0;k<4;++k){
					ri mx=i+d[k][0],my=j+d[k][1];
					if(mx>0&&mx<=n&&my>0&&my<=m&&s[mx][my]=='.')tmp.push_back(idx(mx,my));
				}
				ans[idx(i,j)]=tmp.size()/2*5;
				if(tmp.size()&1)return puts("NO"),0;
				else if(tmp.size()==2)addedge(tmp[0],tmp[1]);
				else if(tmp.size()==4)addedge(tmp[0],tmp[1]),addedge(tmp[1],tmp[2]),addedge(tmp[2],tmp[3]);
			}
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=m;++j)
			if(!ans[idx(i,j)]&&s[i][j]=='.')
				ans[idx(i,j)]=1,dfs(idx(i,j));
	puts("YES");
	for(ri i=1;i<=n;++i,printf("\n"))
		for(ri j=1;j<=m;++j)
			printf("%d ",ans[idx(i,j)]);
	return 0;
}