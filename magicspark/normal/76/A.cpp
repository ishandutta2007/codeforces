#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,G,S;
struct edge{
	int x,y,g,s;
	void input(){scanf("%I64d%I64d%I64d%I64d",&x,&y,&g,&s);};
	bool operator<(const edge&b){
		return g<b.g;
	}
}ed[55555];
inline int cmp(edge a,edge b){
	return a.s<b.s;
}
int par[333];
inline int find(int x){return x==par[x]?x:par[x]=find(par[x]);};
bool del[55555];
signed main(){
	scanf("%I64d%I64d%I64d%I64d",&n,&m,&G,&S);
	for(int i=0;i<m;i++)ed[i].input();
	sort(ed,ed+m);
	long long ans=2e18;
	int r=0;
	for(int i=0;i<m;i++){
		int gg=ed[i].g;
		ed[r++]=ed[i];
		memset(del,false,sizeof(del));
		inplace_merge(ed,ed+r-1,ed+r,cmp);
		for(int i=1;i<=n;i++)par[i]=i;
		int cnt=0;
		for(int j=0;j<r;j++){
			int xx=find(ed[j].x),yy=find(ed[j].y);
			if(xx!=yy){
				cnt++;
				par[xx]=yy;
			}else del[j]=1;
			if(cnt==n-1){
				ans=min(ans,gg*G+S*ed[j].s);
				break;
			}
		}
		int k=0; 
		for(int j=0;j<r;j++)if(!del[j])ed[k++]=ed[j];
		r=k;
	}
	printf("%I64d\n",ans==2e18?-1ll:ans);
	return 0;
}