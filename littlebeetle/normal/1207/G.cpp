#include<cstdio>
#include<vector>
using namespace std;
const int N=400002;
int n,q,i,j,k,opt,h[N],tt[N],v[N],ans[N];
char ch[3],s[N],ti[N];
vector<int>p[N],id[N];
void add(int a,int b){
	tt[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
struct AC{
	int cnt,t[N][26],fail[N],q[N],l,r,i,j,k;
	int H[N],to[N],V[N],dfn[N],sz[N],Tim,c[N],loc[N];
	int insert(char *s){
		for(i=j=1;s[j];j++){
			if(!t[i][s[j]-97])
				t[i][s[j]-97]=++cnt;
			i=t[i][s[j]-97];
		}
		return i;
	}
	void add(int a,int b){
		to[++k]=H[a];
		H[a]=k;
		V[k]=b;
	}
	void dfs(int i){
		dfn[i]=++Tim;
		sz[i]=1;
		for(int j=H[i];j;j=to[j])
			dfs(V[j]),sz[i]+=sz[V[j]];
	}
	void Build(){
		l=0;r=-1;
		for(j=0;j<26;j++)
			if(t[1][j])
				fail[t[1][j]]=1,add(1,t[1][j]),q[++r]=t[1][j];
			else
				t[1][j]=1;
		while(l<=r){
			i=q[l++];
			for(j=0;j<26;j++)
				if(t[i][j])
					fail[t[i][j]]=t[fail[i]][j],add(fail[t[i][j]],t[i][j]),q[++r]=t[i][j];
				else
					t[i][j]=t[fail[i]][j];
		}
		dfs(1);
	}
	void Add(int x,int y){
		while(x)
			c[x]+=y,x-=x&-x;
	}
	int Query(int x){
		int s=0;
		while(x<=cnt)
			s+=c[x],x+=x&-x;
		return s;
	}
	void DFS(int i){
		Add(dfn[loc[i]],1);
		for(int j=0;j<p[i].size();j++)
			ans[id[i][j]]=Query(dfn[p[i][j]])-Query(dfn[p[i][j]]+sz[p[i][j]]);
		for(int j=h[i];j;j=tt[j]){
			loc[v[j]]=t[loc[i]][s[v[j]]-97];
			DFS(v[j]);
		}
		Add(dfn[loc[i]],-1);
	}
	void work(){
		loc[0]=1;
		DFS(0);
	}
}T;
void init(){
	T.cnt=1;
	scanf("%d",&n);
	for(i=1;i<=n;i++,j=0){
		scanf("%d",&opt);
		if(opt==2)
			scanf("%d",&j);
		add(j,i);
		scanf("%s",ch);
		s[i]=*ch;
	}
	scanf("%d",&q);
	for(i=1;i<=q;i++){
		scanf("%d%s",&j,ti+1);
		p[j].push_back(T.insert(ti));
		id[j].push_back(i);
	}
}
int main(){
	init();
	T.Build();
	T.work();
	for(i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}