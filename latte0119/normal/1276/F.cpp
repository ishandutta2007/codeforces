#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
	ost<<"{"<<p.first<<","<<p.second<<"}";
	return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
	ost<<"{";
	for(int i=0;i<v.size();i++){
		if(i)ost<<",";
		ost<<v[i];
	}
	ost<<"}";
	return ost;
}

struct SuffixAutomaton{
	struct State{
		int len,link;
		map<char,int>nex;
		State(int len,int link):len(len),link(link){}
	};

	vector<State>st;
	int last;

	SuffixAutomaton():last(0){
		st.emplace_back(0,-1);
	}

	int process(char c,int cur=-1){
		if(cur==-1){
			cur=last;
		}

		if(st[cur].nex.count(c)){
			int q=st[cur].nex[c];
			if(st[q].len==st[cur].len+1){
				return last=q;
			}
			int clone=st.size();
			st.push_back(st[q]);
			st[clone].len=st[q].len+1;
			st[q].link=clone;
			while(cur!=-1&&st[cur].nex[c]==q){
				st[cur].nex[c]=clone;
				cur=st[cur].link;
			}
			return last=clone;
		}

		int nex=st.size();
		st.emplace_back(st[cur].len+1,0);
		int p=cur;
		while(p!=-1&&!st[p].nex.count(c)){
			st[p].nex[c]=nex;
			p=st[p].link;
		}
		if(p==-1){
			return last=nex;
		}

		int q=st[p].nex[c];
		if(st[p].len+1==st[q].len){
			st[nex].link=q;	
		}
		else{
			int clone=st.size();
			st.push_back(st[q]);
			st[clone].len=st[p].len+1;

			st[q].link=st[nex].link=clone;
			while(p!=-1&&st[p].nex[c]==q){
				st[p].nex[c]=clone;
				p=st[p].link;
			}
		}
		return last=nex;
	}

	
	vector<int>calcTopologicalOrder(){
		vector<int>ord;
		vector<int>deg(st.size());
		for(int i=0;i<st.size();i++){
			for(auto &p:st[i].nex)deg[p.second]++;
		}
		queue<int>que;
		que.push(0);
		while(que.size()){
			int v=que.front();
			que.pop();
			ord.push_back(v);
			for(auto &p:st[v].nex){
				if(--deg[p.second]==0)que.push(p.second);
			}
		}
		return ord;
	}

	vector<int>calcTreeOrder(){
		vector<int>ord;

		vector<vector<int>>G(st.size());
		for(int i=1;i<st.size();i++)G[st[i].link].push_back(i);
		queue<int>que;
		que.push(0);
		while(que.size()){
			int v=que.front();
			que.pop();
			ord.push_back(v);
			for(auto u:G[v])que.push(u);
		}
		return ord;
	}
	long long countDistinctSubstrings(){
		auto ord=calcTopologicalOrder();
		vector<long long>dp(st.size());dp[0]=1;
		for(auto id:ord){
			for(auto &p:st[id].nex)dp[p.se]+=dp[id];
		}
		return accumulate(all(dp),0ll)-1;
	}
};


template<class W>
struct WeightedTree{
	struct Edge{
		int to;
		W cost;
		Edge(int to,W cost):to(to),cost(cost){}
	};

	int V;
	int root;
	int E;
	vector<vector<Edge>>G;

	vector<int>par_,dep_,sz_,head_;
	vector<int>tin_,tout_,vs_;
	vector<W>dist_;
	WeightedTree(int V=0,int root=0):V(V),root(root),G(V),par_(V),sz_(V),dep_(V),head_(V),dist_(V),tin_(V),tout_(V),vs_(V),E(0){}
	void set(int v){
		*this=WeightedTree(v);
	}

	void addEdge(int a,int b,W c=W(1)){
		assert(a<V&&b<V);
		assert(E+1<V);
		G[a].push_back(Edge(b,c));
		G[b].push_back(Edge(a,c));
		E++;
	}

	void dfs(int v,int p,int d,W c){
		par_[v]=p;
		dep_[v]=d;
		sz_[v]=1;
		dist_[v]=c;

		for(auto &e:G[v]){
			if(e.to==p)continue;
			dfs(e.to,v,d+1,c+e.cost);
			sz_[v]+=sz_[e.to];
			if(G[v][0].to==p||sz_[e.to]>sz_[G[v][0].to])swap(G[v][0],e);
		}
	}

	void dfs_hld(int v,int &tt){
		vs_[tt]=v;
		tin_[v]=tt++;
		for(auto &e:G[v]){
			if(e.to==par_[v])continue;
			head_[e.to]=(e.to==G[v][0].to)?head_[v]:e.to;
			dfs_hld(e.to,tt);
		}
		tout_[v]=tt;
	}
	void init(){
		dfs(root,-1,0,W(0));
		int tt=0;
		dfs_hld(root,tt);
	}

	inline int lca(int u,int v)const{
		while(head_[u]!=head_[v]){
			if(dep_[head_[u]]<dep_[head_[v]])swap(u,v);
			u=par_[head_[u]];
		}
		return dep_[u]<dep_[v]?u:v;
	}

	
	inline int ancestor(int v,int k){
		while(v!=-1){
			if(dep_[v]-dep_[head_[v]]<k){
				k-=dep_[v]-dep_[head_[v]]+1;
				v=par_[head_[v]];
				continue;
			}
			return vs_[tin_[v]-k];
		}
		return -1;
	}
	

	inline int par(int v)const{
		return par_[v];
	}

	inline int size(int v)const{
		return sz_[v];
	}
	inline int len(int a,int b=0)const{
		int l=lca(a,b);
		return dep_[a]+dep_[b]-2*dep_[l];
	}
	inline W dist(int a,int b)const{
		int l=lca(a,b);
		return dist_[a]+dist_[b]-2*dist_[l];
	}

	inline W dist(int a)const{
		return dist_[a];
	}

	inline int dep(int v)const{
		return dep_[v];
	}
	inline int tin(int v)const{
		return tin_[v];
	}
	inline int tout(int v)const{
		return tout_[v];
	}

	inline int vs(int k)const{
		return vs_[k];
	}
	inline int heavy(int v)const{
		if(G[v].size()==0||G[v][0].to==par_[v])return -1;
		return G[v][0].to;
	}

	vector<Edge>& operator[](int i){
		return G[i];
	}
};

WeightedTree<int>wt;
WeightedTree<int>T;

vint bucket[333333];
int ans;
int tot;
set<int>ets;

namespace DSUOnTree{
	
	void addX(int x){
		auto it=ets.lower_bound(T.tin(x));
		

		if(it!=ets.end()&&*it<T.tout(x))return;

		int anc=-1;
		if(it!=ets.end()){
			anc=T.lca(T.vs(*it),x);
		}
		if(it!=ets.begin()){
			it--;
			int tmp=T.lca(T.vs(*it),x);
			if(anc==-1||T.dep(anc)<T.dep(tmp))anc=tmp;
		}
		ets.insert(T.tin(x));
		
		if(anc==-1){
			tot+=T.dist(x)+1;
		}
		else{
			tot+=T.dist(x)-T.dist(anc);
		}
	}

	void add(int v){
		for(auto x:bucket[v]){
			addX(x);
		}
	}


	void dfs(int v,int p,bool keep){
		int hv=wt.heavy(v);
		for(auto &e:wt[v]){
			if(e.to!=p&&e.to!=hv)dfs(e.to,v,false);
		}

		if(hv!=-1)dfs(hv,v,true);
		add(v);
		for(auto &e:wt[v])if(e.to!=p&&e.to!=hv){
			for(int i=wt.tin(e.to);i<wt.tout(e.to);i++)add(wt.vs(i));
		}


		//calc

		int len;
		if(v)len=wt.dist(v)-wt.dist(p);
		else len=1;
		ans+=len*tot;
		
	
		if(!keep){
			tot=0;
			ets=set<int>();
		//delete
			for(int i=wt.tin(v);i<wt.tout(v);i++){
				int u=wt.vs(i);
				//delete
			}
		}
	}
	void solve(){
		dfs(0,-1,false);
	}
}

signed main(){
	string S;
	cin>>S;
	int N=S.size();
	SuffixAutomaton suf,pre;
	vint sufid(N+1),preid(N+1);
	rep(i,N){
		sufid[i+1]=suf.process(S[i],sufid[i]);
	}
	for(int i=N-1;i>=0;i--){
		preid[i]=pre.process(S[i],preid[i+1]);
	}


	ans=suf.countDistinctSubstrings();


	wt.set(suf.st.size());
	T.set(pre.st.size());
	for(int i=1;i<suf.st.size();i++){
		auto &nd=suf.st[i];
		wt.addEdge(i,nd.link,nd.len-suf.st[nd.link].len);
	}
	for(int i=1;i<pre.st.size();i++){
		auto &nd=pre.st[i];
		T.addEdge(i,nd.link,nd.len-pre.st[nd.link].len);
	}

	wt.init();
	T.init();

	for(int i=0;i<N;i++){
		int s=sufid[i];
		int p=preid[i+1];
		bucket[s].pb(p);
	}

	DSUOnTree::solve();
	ans++;
	cout<<ans<<endl;	
	return 0;
}