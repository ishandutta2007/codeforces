#include<bits/stdc++.h>
#define log(...) fprintf(stderr,__VA_ARGS__)
#define log(...) (void(0))
template<class T> inline void read(T &x){
	x=0; char c=getchar(); bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
const int N=1e5+10;
int n,root,fa[N],siz[N],mxp[N],dep[N],vis[N],tmp[N];
long long m;
std::set<int> son[N];
std::vector<int> G[N],all[N];
std::set<std::pair<int,int>> set;
std::vector<std::vector<int>> lst;
std::vector<std::pair<int,int>> ans,pos,rst;
std::priority_queue<std::pair<int,int>> q[N];
void error(){
	puts("NO");
	exit(0);
}
void dfs1(int u){
	siz[u]=1;
	for(int v:G[u])if(v!=fa[u]){
		fa[v]=u;
		dfs1(v);
		siz[u]+=siz[v];
		mxp[u]=std::max(mxp[u],siz[v]);
	}
	mxp[u]=std::max(mxp[u],n-siz[u]);
	if(mxp[u]<mxp[root])root=u;
}
void dfs2(int u,int src){
	all[src].push_back(u);
	for(int v:G[u])if(v!=fa[u]){
		fa[v]=u;
		dep[v]=dep[u]+1;
		son[u].insert(v);
		dfs2(v,src);
	}
	if(son[u].size()){
		q[src].push({dep[u],u});
	}
}
std::pair<int,std::pair<int,int>> ask(std::priority_queue<std::pair<int,int>> &q){
	if(!q.size())puts("FUCK!"),error();
	auto it=q.top(); q.pop();
	// if(m==14){
	// 	printf("> %d %d\n",it.first,it.second);
	// }
	int u=it.second;
	if(vis[u]||!son[u].size())return ask(q);
	int x,y;
	if(son[u].size()==1){
		x=u;
		y=*son[u].begin();
		return {dep[u],{x,y}};
	}else{
		x=*son[u].begin();
		y=*std::next(son[u].begin());
		return {dep[u],{x,y}};
	}
}
bool find(int v,int m){
	for(int u:all[v])if(!vis[u]&&son[u].size()&&dep[u]==m){
		vis[u]=vis[*son[u].begin()]=true;
		ans.push_back({u,*son[u].begin()});
		son[u].erase(son[u].begin());
		return true;
	}
	return false;
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n),read(m);
	if(n&1)error();
	for(int u,v,i=1;i<n;i++){
		read(u),read(v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	mxp[root]=n;
	dfs1(1);
	fa[root]=0;
	log("root=%d\n",root);
	for(int v:G[root]){
		fa[v]=root;
		dep[v]=1;
		dfs2(v,v);
		if(all[v].size()>1)set.insert({(int)all[v].size(),v});
		for(int u:all[v])log("[%d] %d > dep=%d son=%d\n",v,u,dep[u],(int)son[u].size());
	}
	m*=-1;
	for(int i=1;i<=n;i++)m+=dep[i];
	if(m<0||(m&1))error();
	m>>=1;
	log("m=%lld\n",m);
	int cnt=0;
	while(m&&set.size()>1){
		auto b=*std::prev(set.end()); set.erase(std::prev(set.end()));
		auto a=*std::prev(set.end()); set.erase(std::prev(set.end()));
		log("m=%d a=%d b=%d\n",(int)m,a.first,b.first);
		// if(m==14){
		// 	log("> ");
		// 	for(int i:all[a.second])if(!vis[i])log("%d ",i);
		// 	log("\n");
		// 	log("> ");
		// 	for(int i:all[b.second])if(!vis[i])log("%d ",i);
		// 	log("\n");
		// }
		auto sa=ask(q[a.second]);
		auto sb=ask(q[b.second]);
		log("SA [%d] >> %d {%d %d}\n",a.second,sa.first,sa.second.first,sa.second.second);
		log("SB [%d] >> %d {%d %d}\n",b.second,sb.first,sb.second.first,sb.second.second);
		// if(n==138){
		// 	if((++cnt)>20)return 0;
		// 	printf("%d %d %d | %d %d %d\n",sa.first,sa.second.first,sa.second.second,sb.first,sb.second.first,sb.second.second);
		// }
		if(m<sa.first+sb.first){
			if(m==1)break;
			int lm=std::min((int)m,sa.first),rm=m-lm;
			if(!rm)--lm,++rm;
			log("LM=%d RM=%d\n",lm,rm);
			assert(find(a.second,lm));
			assert(find(b.second,rm));
			m=0;
			log("BREAK");
			break;
		}
		vis[sa.second.first]=vis[sa.second.second]=1;
		vis[sb.second.first]=vis[sb.second.second]=1;
		const auto check=[&](int x,int v){
			if(fa[x]!=root){
				son[fa[x]].erase(x);
				if(son[x].size())q[v].push({dep[x],x});
				if(son[fa[x]].size())q[v].push({dep[fa[x]],fa[x]});
			}
		};
		check(sa.second.first,a.second);
		check(sa.second.second,a.second);
		check(sb.second.first,b.second);
		check(sb.second.second,b.second);
		m-=sa.first+sb.first;
		ans.push_back(sa.second);
		ans.push_back(sb.second);
		if((a.first-=2)>1)set.insert(a);
		if((b.first-=2)>1)set.insert(b);
	}
	log("m=%lld after set merge\n",m);
	for(int i=1;i<=n;i++)log("%d%c",vis[i]," \n"[i==n]);
	if(m){
		if(m>n)error();
		for(int v:G[root]){
			int cnt=0;
			for(int u:all[v])if(!vis[u])++cnt;
			rst.push_back({cnt,v});
		}
		std::sort(rst.begin(),rst.end());
		std::reverse(rst.begin(),rst.end());
		for(auto it:rst){
			int v=it.second;
			bool fl=find(v,m);
			if(fl){
				m=0;
				break;
			}
		}
		if(m)error();
	}
	for(int v:G[root]){
		std::vector<int> tmp;
		for(int u:all[v])if(!vis[u]){
			tmp.push_back(u);
		}
		if(tmp.size())lst.push_back(tmp);
	}
	// for(int i=1;i<=n;i++)log("%d%c",vis[i]," \n"[i==n]);
	set.clear();
	for(int i=0;i<lst.size();i++)set.insert({(int)lst[i].size(),i});
	// for(const auto &vec:lst){
	// 	printf("VEC :: ");
	// 	for(int x:vec)printf("%d ",x);
	// 	puts("");
	// }
	while(set.size()>1){
		int i=std::prev(set.end())->second; set.erase(std::prev(set.end()));
		int j=std::prev(set.end())->second; set.erase(std::prev(set.end()));
		ans.push_back({lst[i].back(),lst[j].back()});
		lst[i].pop_back();
		lst[j].pop_back();
		if(lst[i].size())set.insert({(int)lst[i].size(),i});
		if(lst[j].size())set.insert({(int)lst[j].size(),j});
	}
	if(set.size()){
		int i=set.begin()->second;
		if(vis[root]){
			error();
		}else{
			if(lst[i].size()!=1)error();
			ans.push_back({root,lst[i][0]});
		}
	}
	puts("YES");
	for(const auto &it:ans){
		print(it.first,' ');
		print(it.second,'\n');
	}
}