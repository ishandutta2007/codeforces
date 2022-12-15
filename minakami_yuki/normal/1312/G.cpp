#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#define LL long long
using namespace std;
const int N=1e6+10;
const LL P=998244353;
int n,m,cnt,las;
struct date{
	int p;
	char c;
}a[N];
int b[N];
int vis[N];
int g[N][26];
int t[N][2];
int sz[N];
//void DP(int x){
//	if(vis[x]) sz[x]=1;
//	for(int i=0;i<26;++i){
//		if(g[x][i]){
//			DP(g[x][i]);
//			sz[x]+=sz[g[x][i]];
//		}
//	}
//}
void dfs(int x){
	int y;
	if(vis[x]) ++sz[x];
	for(int i=0;i<26;++i){
		if(g[x][i]){
			y=g[x][i];
			t[y][0]=t[x][0]+1;
			if(vis[y]) t[y][1]=t[x][1]+1+sz[x]-vis[x];
			else t[y][1]=t[x][1]+sz[x]-vis[x];
			t[y][1]=min(t[y][1],t[x][0]+sz[x]+vis[y]);
			if(vis[x]) t[y][0]=min(t[y][0],t[x][1]+1);
			dfs(g[x][i]);
			sz[x]+=sz[g[x][i]];
		}
	}
}
int main(){
	cin>>n;
	t[0][0]=t[0][1]=0;
	for(int i=1;i<=n;++i){
		scanf("%d%s",&a[i].p,&a[i].c);
		g[a[i].p][a[i].c-'a']=i;
	}
	cin>>m;
	int x;
	for(int i=1;i<=m;++i) {
		scanf("%d",&b[i]);
		vis[b[i]]=1;
	}
	//DP(0); 
	dfs(0);
	//cout<<t[5][0]<<" "<<t[5][1]<<endl;
	for(int i=1;i<=m;++i) printf("%d ",min(t[b[i]][0],t[b[i]][1]));
	cout<<endl;
	return 0;
}