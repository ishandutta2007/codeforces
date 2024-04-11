#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,h,w,tp[N],pos[N],t[N],x[N];
//id 
vector<int> vx[N],vy[N];
pair<int,int> ans[N];
bool cmp(int x,int y){
	return pos[x]<pos[y];
}
int main()
{
	scanf("%d%d%d",&n,&w,&h);
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&tp[i],&pos[i],&t[i]);
		x[i]=pos[i]-t[i]+1e5;
		if (tp[i]==1) vx[x[i]].push_back(i);
			else vy[x[i]].push_back(i);
	}
	for (int i=1;i<=2e5;i++){
		int cntx=vx[i].size();
		int cnty=vy[i].size();
		sort(vx[i].begin(),vx[i].end(),cmp);
		sort(vy[i].begin(),vy[i].end(),cmp);
		for (int j=0;j<cntx;j++){
			int id=vx[i][j];
			int right=cntx-j;
			if (right>cnty) ans[id]=make_pair(pos[vx[i][j+cnty]],h);
				else ans[id]=make_pair(w,pos[vy[i][right-1]]);
		}
		for (int j=0;j<cnty;j++){
			int id=vy[i][j];
			int up=cnty-j;
			if (up>cntx) ans[id]=make_pair(w,pos[vy[i][j+cntx]]);
				else ans[id]=make_pair(pos[vx[i][up-1]],h);
		}
	}
	for (int i=1;i<=n;i++) printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}