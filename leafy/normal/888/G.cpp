#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
const int N=200005;
int n;
int a[N];
int ch[N*30][2],tot;
ll ans=0;
inline void ins(int x){
	int rt=0;
	for(int i=29;i>=0;i--){
		int t=(x>>i)&1;
		if(!ch[rt][t]) ch[rt][t]=++tot;
		rt=ch[rt][t]; 
	}
}
int calc(int u,int v,int w){
	if(w<0) return 0;
	int res1=-1,res2=-1;
	if(ch[u][0]&&ch[v][0]) res1=calc(ch[u][0],ch[v][0],w-1);
	if(ch[u][1]&&ch[v][1]) res2=calc(ch[u][1],ch[v][1],w-1);
	if(res1==-1&&res2==-1){
		if(ch[u][0]&&ch[v][1]) res1=calc(ch[u][0],ch[v][1],w-1)+(1<<w);
		if(ch[u][1]&&ch[v][0]) res2=calc(ch[u][1],ch[v][0],w-1)+(1<<w);
	}
	if(res1!=-1&&res2!=-1) return min(res1,res2);
	return max(res1,res2);
}
void dfs(int u,int d){
	if(ch[u][0]&&ch[u][1]) ans+=calc(ch[u][0],ch[u][1],d-1)+(1<<d);
	if(ch[u][0]) dfs(ch[u][0],d-1);
	if(ch[u][1]) dfs(ch[u][1],d-1);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++) a[i]=read(),ins(a[i]);
	dfs(0,29);
	cout<<ans;
	return 0;
}