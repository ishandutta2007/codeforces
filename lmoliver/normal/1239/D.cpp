#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=2002002;
vector<int> es[N];
void ae(int u,int v){
	es[u].push_back(v);
}
int dfn[N]={0};
int low[N];
bool ins[N]={false};
stack<int> st;
int cls=0;
int color[N];
vector<int> colors[N];
int dft=0;
void dfs(int x){
	low[x]=dfn[x]=++dft;
	st.push(x);
	ins[x]=true;
	for(int ch:es[x]){
		if(!dfn[ch]){
			dfs(ch);
			low[x]=min(low[x],low[ch]);
		}
		else if(ins[ch]){
			low[x]=min(low[x],dfn[ch]);
		}
	}
	if(low[x]==dfn[x]){
		int c=++cls;
		int p;
		do{
			p=st.top();
			st.pop();
			ins[p]=false;
			color[p]=c;
			colors[c].push_back(p);
		}while(p!=x);
	}
}
int n,m;
bool b[N]={false};
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			es[i].clear();
			dfn[i]=0;
			low[i]=0;
			color[i]=0;
			colors[i].clear();
			b[i]=false;
		}
		dft=0;
		cls=0;
		while(m--){
			int a,b;
			scanf("%d%d",&a,&b);
			if(a!=b){
				ae(a,b);
			}
		}
		for(int i=1;i<=n;i++){
			if(!dfn[i]){
				dfs(i);
			}
		}
		if(cls==1){
			puts("No");
			continue;
		}
		puts("Yes");
		printf("%d %d\n",(int)colors[1].size(),(int)(n-colors[1].size()));
		for(auto a:colors[1]){
			printf("%d ",a);
			b[a]=true;
		}
		printf("\n");
		for(int i=1;i<=n;i++){
			if(!b[i]){
				printf("%d ",i);
			}
		}
		printf("\n");
	}
	return 0;
}