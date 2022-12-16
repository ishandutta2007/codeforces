#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> V;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)
#define R(N,S,E) for(int N=(int)(S);N>=(int)(E);N--)
#define D(N,E) for(int N=(int)(0);N<(int)(E);N++)
LL read(){LL x;scanf("%lld",&x);return x;}

const int N=3.1e5;

struct E{int v,id,d;};
vector<E> es1[N],es2[N];

int sz[N];
bool used[N];
vector<pair<int,vector<E>>> trains;
void dfs(const vector<E> es[N],vector<E> &out,int x){
	// cerr<<"d"<<x<<endl;
	while(sz[x]){
		sz[x]--;
		E e=es[x][sz[x]];
		if(exchange(used[e.id],true))continue;
		out.push_back(e);
		dfs(es,out,e.v);
		break;
	}
}
void run(const vector<E> es[N],int n){
	// cerr<<"r"<<endl;
	trains.clear();
	memset(used,false,sizeof(used));
	F(i,1,n)sz[i]=es[i].size();
	F(i,1,n)while(sz[i]){
		// cerr<<"l"<<endl;
		vector<E> out;
		dfs(es,out,i);
		vector<E> out2;
		dfs(es,out2,i);
		int l=i;
		for(E &e:out2){
			swap(l,e.v);
			e.d^=3;
		}
		reverse(out2.begin(),out2.end());
		out.insert(out.begin(),out2.begin(),out2.end());
		if(!out.empty())trains.push_back({l,out});
	}
}

pair<int,bool> follow[N];

int dbu[N],dbv[N],dbw[N];
int ans[N];

int main(){
	int n=read(),m=read();
	D(i,m)follow[i].first=-1;
	D(i,m){
		int u=read(),v=read(),w=read();
		dbu[i]=u;
		dbv[i]=v;
		dbw[i]=w;
		if(w==1){
			es1[u].push_back({v,i,1});
			es1[v].push_back({u,i,2});
		}
		else{
			es2[u].push_back({v,i,1});
			es2[v].push_back({u,i,2});
		}
	}
	
	int cnt=0;
	F(i,1,n)cnt+=es1[i].size()&1;

	run(es2,n);
	for(const auto &t:trains){
		int u=t.first;
		int v=t.second.back().v;
		if(u!=v){
			int id=t.second[0].id;
			int d=t.second[0].d;
			F(i,1,(int)t.second.size()-1){
				follow[t.second[i].id]={id,t.second[i].d==d};
			}
			es1[u].push_back({v,id,d});
			es1[v].push_back({u,id,3-d});
		}
		else{
			for(E e:t.second)ans[e.id]=e.d;
		}
	}
	
	run(es1,n);
	for(const auto &t:trains){
		for(E e:t.second){
			ans[e.id]=e.d;
		}
	}
	D(i,m)if(follow[i].first!=-1){
		int pd=ans[follow[i].first];
		ans[i]=follow[i].second?pd:3-pd;
	}
	printf("%d\n",cnt);
	D(i,m)printf("%d",ans[i]);
	printf("\n");

	static int dd[N]={0};
	D(i,m){
		int w=ans[i]==1?1:-1;
		dd[dbu[i]]+=w*dbw[i];
		dd[dbv[i]]-=w*dbw[i];
	}
	int dbcnt=0;
	F(i,1,n)if(abs(dd[i])==1){
		dbcnt++;
	}
	if(dbcnt!=cnt)cerr<<"GG"<<endl;
	return 0;
}