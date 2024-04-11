#include<cstdio>
#include<algorithm>
#define MAXN 200000
#define MAXM 400000
using namespace std;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
int n,m,cnt,s,t,ds,dt;
typedef pair<int,int>pii;
bool vis[MAXN+10][2];
struct Edge{
	int u,v;
	inline Edge(){
	}
	inline Edge(int u,int v):u(u),v(v){
	}
}eset[MAXM+10],ans[MAXM+10],pp[MAXN+10][2];
int fa[MAXN+10];
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void read(){
	Read(n),Read(m);
	
	int i,u,v;
	for(i=1;i<=n;i++){
		fa[i]=i;
	}
	for(i=1;i<=m;i++){
		Read(u),Read(v);
		eset[i]=Edge(u,v);
	}Read(s),Read(t),Read(ds),Read(dt);
	for(i=1;i<=m;i++){
		u=eset[i].u,v=eset[i].v;
		if(u==s||u==t||v==s||v==t)
			continue;
		if(find(u)!=find(v)){
			fa[fa[u]]=fa[v];
			ans[++cnt]=eset[i];
		}
	}
}
bool okst;
int d[2];
void solve(){
	int i;
	for(i=1;i<=m;i++){
		if(eset[i].u==s&&eset[i].v==t||eset[i].u==t&&eset[i].v==s)
			okst=1;
		else if(eset[i].u==s||eset[i].v==s){
			if(eset[i].u==s){
				if(!vis[find(eset[i].v)][0])
					vis[fa[eset[i].v]][0]=1,pp[fa[eset[i].v]][0]=eset[i];
			}
			else{
				if(!vis[find(eset[i].u)][0])
					vis[fa[eset[i].u]][0]=1,pp[fa[eset[i].u]][0]=eset[i];
			}
		}
		else if(eset[i].u==t||eset[i].v==t){
			if(eset[i].u==t){
				if(!vis[find(eset[i].v)][1])
					vis[fa[eset[i].v]][1]=1,pp[fa[eset[i].v]][1]=eset[i];
			}
			else{
				if(!vis[find(eset[i].u)][1])
					vis[fa[eset[i].u]][1]=1,pp[fa[eset[i].u]][1]=eset[i];
			}
		}
	}
	for(i=1;i<=n;i++)
		if(find(i)==i)
			if(vis[i][0]+vis[i][1]==1){
				if(vis[i][0]){
					ans[++cnt]=pp[i][0];
					d[0]++;
				}
				else
					ans[++cnt]=pp[i][1],d[1]++;
			}
	bool flag=0;
		if(d[0]>ds||d[1]>dt){
				puts("No");
				exit(0);
		}
	if(!okst){
		for(i=1;i<=n;i++){
			if(find(i)==i)
				if(vis[i][0]+vis[i][1]==2){
					if(!flag){
						ans[++cnt]=pp[i][0];
						d[0]++;
						ans[++cnt]=pp[i][1],d[1]++;
						flag=1;
						continue;
					}
					if(d[0]<ds){
						ans[++cnt]=pp[i][0];
						d[0]++;
					}
					else
						ans[++cnt]=pp[i][1],d[1]++;
				}
			if(d[0]>ds||d[1]>dt){
				puts("No");
				exit(0);
			}
		}
	}
	else{
		for(i=1;i<=n;i++)
			if(find(i)==i)
				if(vis[i][0]+vis[i][1]==2){
					if(d[0]<ds-1||flag&&d[0]<ds){
						ans[++cnt]=pp[i][0];
						d[0]++;
					}
					else if(d[1]<ds-1||flag&&d[1]<dt)
						ans[++cnt]=pp[i][1],d[1]++;
					else{
						if(!flag){
							ans[++cnt]=pp[i][0];
							d[0]++;
							ans[++cnt]=pp[i][1],d[1]++;
							flag=1;
						}
						else{
								puts("No");
								exit(0);
							
						}
					}
				}
		if(!flag){
			if(d[0]<ds&&d[1]<dt)
				ans[++cnt]=Edge(s,t);
			else{
				puts("No");
				exit(0);
			}
		}
	}
}
void print(){
	puts("Yes");
	for(int i=1;i<=cnt;i++)
		printf("%d %d\n",ans[i].u,ans[i].v);
}
int main()
{
	read();
	solve();
	print();
}