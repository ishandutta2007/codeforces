#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<vector>
typedef long long ll;
using namespace std;
typedef pair<int,int> pr;
#define mkp make_pair
const int MAXN=1e5+5;
int n,m;
int cnte,h[MAXN],to[MAXN<<1],nx[MAXN<<1],ww[MAXN<<1];
inline void adde(int u,int v,int w){
	cnte++;
	nx[cnte]=h[u];
	to[cnte]=v;
	ww[cnte]=w;
	h[u]=cnte;
}
vector<pr> fish[MAXN];
struct Adj{
	int dis,l;
};
bool operator <(Adj a,Adj b){
	return a.dis>b.dis;
}
struct node{
	map<int,int> a,b;
	int tag;
	priority_queue<Adj> que;
	void Add(int x,int y){
		auto it1=a.find(x+tag),it2=b.find(x-tag);
		if(it1!=a.end()){
			a[x+tag]+=y;
			return ;
		}
		if(it2!=b.end()){
			if(it2->second>y){
				b[x-tag]-=y;
				return ;
			}
			if(it2->second==y){
				if(it2!=b.begin()){
					auto l=it2;
					l--;
					auto r=a.lower_bound(x+tag);
					if(r!=a.end()) que.push(Adj{r->first-l->first,l->first});
				}
				b.erase(it2);
				return ;
			}
			a[x+tag]=y-it2->second;
			if(it2!=b.begin()){
				auto l=it2;
				l--;
				que.push(Adj{x+tag-l->first,l->first});
			}
			b.erase(it2);
			return ;
		}
		a[x+tag]=y;
		it2=b.lower_bound(x-tag);
		if(it2!=b.begin()){
			it2--;
			que.push(Adj{x+tag-it2->first,it2->first});
		}
		return ;
	}
	void Sub(int x,int y){
		auto it1=a.find(x+tag),it2=b.find(x-tag);
		if(it2!=b.end()){
			b[x-tag]+=y;
			return ;
		}
		if(it1!=a.end()){
			if(it1->second>y){
				a[x+tag]-=y;
				return ;
			}
			if(it1->second==y){
				auto r=it1;
				r++;
				if(r!=a.end()){
					auto l=b.lower_bound(x-tag);
					if(l!=b.begin()){
						l--;
						que.push(Adj{r->first-l->first,l->first});
					}
				}
				a.erase(it1);
				return ;
			}
			b[x-tag]=y-it1->second;
			auto r=it1;
			r++;
			if(r!=a.end())
				que.push(Adj{r->first-(x-tag),x-tag});
			a.erase(it1);
			return ;
		}
		b[x-tag]=y;
		it1=a.lower_bound(x+tag);
		if(it1!=a.end())
			que.push(Adj{it1->first-(x-tag),x-tag});
		return ;
	}
	void Move(int x){
		tag+=x;
		while(!que.empty()){
			Adj t=que.top();
			if(t.dis>tag*2) break;
			que.pop();
			auto it1=b.find(t.l),it2=a.find(t.l+t.dis);
			if(it1==b.end()||it2==a.end()) continue;
			if(it1->second>it2->second){
				b[t.l]-=it2->second;
				auto r=it2;
				r++;
				if(r!=a.end())
					que.push(Adj{r->first-t.l,t.l});
				a.erase(it2);
			}else if(it1->second<it2->second){
				a[t.l+t.dis]-=it1->second;
				if(it1!=b.begin()){
					auto l=it1;
					l--;
					que.push(Adj{t.l+t.dis-l->first,l->first});
				}
				b.erase(it1);
			}else{
				b.erase(it1);
				a.erase(it2);
				it1=b.lower_bound(t.l);
				it2=a.lower_bound(t.l+t.dis);
				if(it1!=b.begin()&&it2!=a.end()){
					it1--;
					que.push(Adj{it2->first-it1->first,it1->first});
				}
			}
		}
		return ;
	}
	int Query(int x){
		int res=0;
		auto it=b.find(x-tag);
		if(it!=b.end()) res=it->second;
		it=a.find(x+tag+1);
		if(it!=a.end()) res=max(res,it->second);
		return res;
	}
	int Ans(){
		int res=0,sum=0;
		vector<pr> x;
		for(auto i:a)
			x.emplace_back(i.first-tag,i.second);
		for(auto i:b)
			x.emplace_back(i.first+tag,-i.second);
		sort(x.begin(),x.end());
		for(auto i:x)
			res=max(res,sum+=i.second);
		return res;
	}
	void Print(){
		printf("tag %d\n",tag);
		for(auto i:a)
			printf("%d add %d\n",i.first,i.second);
		for(auto i:b)
			printf("%d sub %d\n",i.first,i.second);
		priority_queue<Adj> tmp=que;
		while(!tmp.empty()){
			Adj t=tmp.top();
			tmp.pop();
			printf("que %d l %d\n",t.dis,t.l);
		}
		return ;
	}
}f[MAXN];
void Merge(node &a,node &b){
	if(a.a.size()+a.b.size()<b.a.size()+b.b.size()) swap(a,b);
	for(auto i:b.a)
		a.Add(i.first-b.tag,i.second);
	for(auto i:b.b)
		a.Sub(i.first+b.tag,i.second);
	priority_queue<Adj> tmp;
	swap(tmp,b.que);
	return ;
}
int fa[MAXN];
void Dfs(int u){
	for(int i=h[u]; i; i=nx[i]){
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		Dfs(v);
		f[v].Move(ww[i]-1);
		Merge(f[u],f[v]);
	}
	for(int i=0; i<fish[u].size(); i++)
		fish[u][i].second-=f[u].Query(fish[u][i].first);
	f[u].Move(1);
	for(auto i:fish[u])
		if(i.second>0) f[u].Add(i.first,i.second),f[u].Sub(i.first+1,i.second);
	//printf("u %d\n",u);
	//f[u].Print();
	return ;
}
int main(){
	//freopen("in","r",stdin);
	scanf("%d",&n);
	for(int i=1; i<n; i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		w<<=1;
		adde(u,v,w);
		adde(v,u,w);
	}
	scanf("%d",&m);
	while(m--){
		int d,f,p;
		scanf("%d%d%d",&d,&f,&p);
		fish[p].emplace_back(d*2,f);
	}
	Dfs(1);
	printf("%d\n",f[1].Ans());
	return 0;
}