#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
const int N=5e5+10;
int T,n,m,col[N],deg[N];
std::vector<int> G[N];
std::vector<std::pair<int,int>> E;
std::vector<int> without(const std::vector<int> &a){
	std::vector<bool> sta(n+1,false);
	for(int i=0;i<a.size();i++)sta[a[i]]=true;
	std::vector<int> b;
	for(int i=1;i<=n;i++)if(!sta[i])b.push_back(i);
	return b;
}
std::vector<int> getpath(int u,const std::vector<int> &nxt){
	std::vector<int> res;
	while(u)res.push_back(u),u=nxt[u];
	return res;
}
void init(){
	read(n),read(m);
	E.clear();
	for(int i=1;i<=n;i++)G[i].clear();
	for(int u,v,i=1;i<=m;i++){
		read(u),read(v);
		E.push_back({u,v});
		G[u].push_back(v),G[v].push_back(u);
	}
}
void solve(){
	int tem=0;
	for(int i=1;i<=n;i++){
		deg[i]=G[i].size();
		col[i]=G[i].size()%3;
		if(col[i]==1&&!tem)tem=i;
	}
	// for(int i=1;i<=n;i++)printf("%d%c",deg[i]," \n"[i==n]);
	std::vector<std::function<void(void)>> checker={
		[&](){ //=>
			bool fl=true;
			for(int i=1;i<=n;i++)fl&=deg[i]==2;
			if(fl)throw std::vector<int>{};
		},
		[&](){ //C
			for(int i=1;i<=n;i++)if(!col[i])throw without({i});
		},
		[&](){ //ABB...BBA
			int cnt=0;
			for(int i=1;i<=n;i++)cnt+=col[i]==1;
			if(cnt<2)return;
			int s=tem,e=0,u;
			std::queue<int> q;
			std::vector<int> pre(n+1),dis(n+1);
			dis[s]=1,q.push(s);
			while(q.size()){
				u=q.front(),q.pop();
				for(int v:G[u])if(!dis[v]){
					dis[v]=dis[u]+1;
					pre[v]=u;
					q.push(v);
				}
			}
			for(int i=1;i<=n;i++)if(col[i]==1&&i!=s){
				if(!e||dis[e]>dis[i])e=i;
			}
			throw without(getpath(e,pre));
		},
		[&](){ //B && B
			std::vector<int> pre(n+1),dep(n+1);
			std::vector<bool> vis(n+1,false);
			std::vector<std::pair<int,int>> pos;
			std::function<std::vector<int>(int,int)> findway=[&](int s,int e){
				try{
					std::vector<int> stk;
					std::function<void(int,int)> dfs=[&](int u,int fa){
						stk.push_back(u);
						if(u==e)throw stk;
						for(int v:G[u])if(v!=fa&&col[v]==2){
							dfs(v,u);
						}
						stk.pop_back();
					};
					dfs(s,0);
				}catch(std::vector<int> res){
					return res;
				}
				return std::vector<int>{};
			};
			std::function<void(int,int,int,int&)> dfs=[&](int u,int fa,int cur,int &tar){
				vis[u]=true;
				dep[u]=dep[fa]+1;
				for(int v:G[u])if(col[v]==1){
					if(u!=cur&&!~tar)tar=u;
				}
				std::vector<std::pair<int,int>> ret;
				for(int v:G[u])if(v!=fa&&vis[v]){
					ret.push_back({dep[v],v});
				}
				if(ret.size()){
					int v=(*std::max_element(ret.begin(),ret.end())).second;
					pre[v]=0;
					throw without(getpath(u,pre));
				}
				for(int v:G[u])if(v!=fa&&col[v]==2){
					pre[v]=u;
					dfs(v,u,cur,tar);
				}
			};
			int tar=-1;
			if(tem){
				for(int cur:G[tem])if(!vis[cur]){
					tar=-1,dfs(cur,0,cur,tar);
					pos.push_back({cur,tar});
				}
				if(pos.size()<2)throw std::vector<int>{};
				// printf("tem %d | %d %d %d %d\n",tem,pos[0].first,pos[0].second,pos[1].first,pos[1].second);
				std::vector<int> res={tem},now;
				now=findway(pos[0].first,pos[0].second),res.insert(res.end(),now.begin(),now.end());
				now=findway(pos[1].first,pos[1].second),res.insert(res.end(),now.begin(),now.end());
				throw without(res);
			}else{
				dfs(1,0,0,tar);
				throw std::vector<int>{};
			}
		},
	};
	for(const auto &func:checker)func();
	assert(false);
}
void stealData(int x,int y){
	if(T!=x)return;
	for(int u,v,i=1;i<=T;i++){
		read(n),read(m);
		if(i==y)printf("%d %d\n",n,m);
		for(int j=1;j<=m;j++){
			read(u),read(v);
			if(i==y)printf("%d %d\n",u,v);
		}
	}
	exit(0);
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(read(T);T--;){
		init();
		try{
			solve();
		}catch(std::vector<int> ans){
			if(ans.size()){
				putchar('Y'),putchar('E'),putchar('S'),putchar('\n');
				print(ans.size(),'\n');
				for(int i=0;i<ans.size();i++)print(ans[i]," \n"[i+1==ans.size()]);
			}else{
				putchar('N'),putchar('O'),putchar('\n');
			}
		}
	}
}