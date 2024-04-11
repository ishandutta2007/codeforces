#include<bits/stdc++.h>
using namespace std;
 
#define int long long 
 
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
 
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

struct Dinic{
    using F=long long;
    static const F INF;

    struct Edge{
        int from,to;
        F cap;
        int rev;
		int id;
    };

    int n;
    vector<vector<Edge>>G;
    vector<int>iter,level;
    Dinic(int n):n(n),G(n),iter(n),level(n){}
    inline void addEdge(int from,int to,F cap,int id=-1){
        G[from].push_back(Edge{from,to,cap,G[to].size(),id});
        G[to].push_back(Edge{to,from,0,G[from].size()-1,id});
    }
    inline void addUndirectedEdge(int from,int to,F cap,int id=-1){
        G[from].push_back(Edge{from,to,cap,G[to].size(),id});
        G[to].push_back(Edge{to,from,cap,G[from].size()-1,id});
    }

    void bfs(int s){
        level.assign(n,-1);
        queue<int>que;
        level[s]=0;
        que.push(s);
        while(que.size()){
            int u=que.front();
            que.pop();
            for(auto &e:G[u]){
                if(e.cap==0||level[e.to]!=-1)continue;
                level[e.to]=level[u]+1;
                que.push(e.to);
            }
        }
    }

    F dfs(const int &s,const int &u,F cur){
        if(s==u)return cur;
        F sum=0;
        for(int &i=iter[u];i<G[u].size();i++){
            Edge &e=G[u][i],&ee=G[e.to][e.rev];
            const int &v=e.to;
            if(level[v]>=level[u]||ee.cap==0)continue;
            F f=dfs(s,v,min(cur-sum,ee.cap));
            if(f<=0)continue;
            ee.cap-=f;e.cap+=f;
            sum+=f;
            if(sum==cur)break;
        }
        return sum;
    }


    F maxFlow(int s,int t){
        F flow=0;
        while(true){
            bfs(s);
            if(level[t]==-1)return flow;
            iter.assign(n,0);
            flow+=dfs(s,t,INF);
        }
    }
};
const Dinic::F Dinic::INF=1ll<<50;

signed main(){
	int N1,N2,M;

	cin>>N1>>N2>>M;
	Dinic d(N1+N2+2);
	int src=N1+N2;
	int snk=src+1;


	vint deg1(N1),deg2(N2);
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--;b--;
		deg1[a]++;
		deg2[b]++;
		d.addEdge(a,b+N1,1,i);
	}

	int K=min(*min_element(all(deg1)),*min_element(all(deg2)));

	rep(i,N1){
		d.addEdge(src,i,deg1[i]-K);
	}
	rep(i,N2){
		d.addEdge(N1+i,snk,deg2[i]-K);
	}


	vector<vint>ans;
	for(int i=K;i>=0;i--){
		d.maxFlow(src,snk);
		ans.eb();
		rep(a,N1)for(auto &e:d.G[a]){
			if(e.to==src)continue;
			if(e.cap==0)continue;
			ans.back().pb(e.id);
		}

		if(i==0)break;
		for(auto &e:d.G[src])e.cap++;
		for(auto &e:d.G[snk]){
			d.G[e.to][e.rev].cap++;
		}
	}

	reverse(all(ans));
	for(auto &v:ans){
		printf("%lld",(int)v.size());
		for(auto k:v)printf(" %lld",k+1);
		puts("");
	}
	return 0;
}