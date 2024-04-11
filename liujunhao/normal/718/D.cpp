#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#define MAXN 100000
using namespace std;
int n,cnt,d[MAXN+10];
map<int,int>hash[MAXN+10];
map<vector<int>,int>pp;
set<vector<int> >qq;
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
struct node{
	int v;
	node *next;
}*adj[MAXN+10],edge[MAXN*2+10],*ecnt=edge;
inline void addedge(int u,int v){
	node *p=++ecnt;
	p->v=v;
	p->next=adj[u];
	adj[u]=p;
}
int dfs(int u,int fa){
	if(hash[u].count(fa))
		return hash[u][fa];
	vector<int>s;
	for(node *p=adj[u];p;p=p->next)
		if(p->v!=fa)
			s.push_back(dfs(p->v,u));
	if(!s.size())
		return hash[u][fa]=0;
	sort(s.begin(),s.end());
	if(pp.count(s))
		return hash[u][fa]=pp[s];
	else
		return hash[u][fa]=pp[s]=++cnt;
}
void read(){
	Read(n);
	int i,u,v;
	for(i=1;i<n;i++){
		Read(u),Read(v);
		d[u]++,d[v]++;
		addedge(u,v);
		addedge(v,u);
	}
}
void solve(){
	int i;
	for(i=1;i<=n;i++){
		if(d[i]<4){
			vector<int>s;
			for(node *p=adj[i];p;p=p->next)
				s.push_back(dfs(p->v,i));
			sort(s.begin(),s.end());
			qq.insert(s);
		}	
	}
}
int main()
{
	read();
	solve();
	printf("%u\n",qq.size());
}