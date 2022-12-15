#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#define LL long long
using namespace std;
const int N=2e5+10;
const int M=3e5+10;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
int n,m,cnt=1;
struct edge{
	int r,nxt;
	int c;
}e[M<<1];
int a[N],b[N];
double ans[N],X;
int vis[N],vis2[N],hed[N];
bool f,youjie;
void insert(int u,int v,int c){
	e[++cnt].r=v;e[cnt].c=c;e[cnt].nxt=hed[u];hed[u]=cnt;
}
void J(int A,int B,int c){
	c=c-B;
	if((!A)&&(!c)) return;
	if(!A) {youjie=0;return;}
	double y=(double)c/(double)A;
	if((!f)||y==X) {X=y;f=1;return;}
	youjie=0;return;
}

int q[N];int top;
void dfs(int u){
	int v;
	for(int i=hed[u];i&&youjie;i=e[i].nxt){
		v=e[i].r;
		if(!vis[v]){
			vis[v]=1;
			a[v]=-a[u];
			b[v]=e[i].c-b[u];
			q[++top]=-a[v]*b[v];
			dfs(v);
		}
		else{
			J(a[u]+a[v],b[u]+b[v],e[i].c);
		}
	}
}
void getans(int u){
	ans[u]=(double)a[u]*X+(double)b[u];
	for(int i=hed[u];i;i=e[i].nxt)
		if(!vis2[e[i].r]) {
			vis2[e[i].r]=1;
			getans(e[i].r);
		}
}
int main(){
	int u,v,c;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&u,&v,&c);
		insert(u,v,c);insert(v,u,c);
	}
	bool flag=1;
	for(int i=1;i<=n;++i){
		if(vis[i]) continue;
		a[i]=1;b[i]=0;f=0;youjie=1;vis[i]=1;top=1;q[1]=0;
		dfs(i);
		if(!youjie) {
			flag=0;
			break;
		}
		
		if(!f){
			sort(q+1,q+1+top);
			X=q[(top+1)/2];
		}
		vis2[i]=1;
		getans(i);
	}
	if(!flag) printf("NO\n");
	else {
		printf("YES\n");
		for(int i=1;i<=n;++i) cout<<ans[i]<<" ";
		puts("");
	}
	return 0;
}