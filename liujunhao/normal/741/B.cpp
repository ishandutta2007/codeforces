#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<iostream>
#define MAXN 1000
using namespace std;
int n,m,wt[MAXN+10],b[MAXN+10],fa[MAXN+10],tw[MAXN+10],tb[MAXN+10],w,f[2][MAXN+10];
vector<int>c[MAXN+10];
void Read(int &x){
	char c;
	while(c=getchar(),c!=EOF)
		if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			return;
		}
}
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void read(){
	Read(n),Read(m),Read(w);
	int i,u,v;
	for(i=1;i<=n;i++){
		Read(wt[i]);
		fa[i]=i;
	}
	for(i=1;i<=n;i++)
		Read(b[i]);
	for(i=1;i<=m;i++){
		Read(u),Read(v);
		if(find(u)!=find(v)){
			fa[fa[u]]=fa[v];
		}
	}
}
void solve(){
	int i,j,now=0;
	for(i=1;i<=n;i++){
		tw[find(i)]+=wt[i];
		tb[find(i)]+=b[i];
		c[find(i)].push_back(i);
	}
	for(i=1;i<=n;i++){
		if(find(i)==i){
			now^=1;
			memcpy(f[now],f[now^1],sizeof f[now]);
			for(j=w;j>=tw[i];j--)
				f[now][j]=max(f[now][j],f[now^1][j-tw[i]]+tb[i]);
			for(auto k=c[i].begin();k!=c[i].end();k++)
				for(j=w;j>=wt[*k];j--)
					f[now][j]=max(f[now][j],f[now^1][j-wt[*k]]+b[*k]);
		}
	}
	printf("%d\n",f[now][w]);
}
int main()
{
	read();
	solve();
}