#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2010;
inline void ask(int k){
	printf("? %d\n",k);
	fflush(stdout);
}
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
set<pii>ans;
int dis[2][maxn],n,tmp[maxn];
bool vis[maxn];
vector<int>son;
inline bool cmp(const int &x,const int &y){
	return dis[1][x]>dis[1][y];
}
int main(){
	scanf("%d",&n);
	ask(1);
	for(ri i=1;i<=n;++i){
		scanf("%d",dis[1]+i);
		if(i>1)son.push_back(i);
	}
	sort(son.begin(),son.end(),cmp);
	for(auto i:son){
		if(vis[i])continue;
		if(dis[1][i]==1)ans.insert({1,i});
		else{
			ask(i);
			vis[i]=true;
			for(ri j=1;j<=n;++j){
				scanf("%d",dis[0]+j);
				if(dis[1][j]+dis[0][j]==dis[1][i])tmp[dis[1][j]]=j,vis[j]=true;
			}
			for(ri j=1;j<=dis[1][i];++j){
				ans.insert({min(tmp[j-1],tmp[j]),max(tmp[j-1],tmp[j])});
				for(ri k=1;k<=n;++k){
					if(vis[k])continue;
					if(dis[0][k]-dis[0][tmp[j]]==1&&dis[1][k]-dis[1][tmp[j]]==1){
						ans.insert({min(tmp[j],k),max(tmp[j],k)});
						vis[k]=true;
					}
				}
			}
		}
	}
	putchar('!');
	putchar(10);
	for(auto i:ans)printf("%d %d\n",i.fi,i.se);
	fflush(stdout);
	return 0;
}