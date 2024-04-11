#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
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

struct ModA{
	static uint32_t mod; 
	uint32_t a;
	ModA& s(uint32_t vv){
		a=vv<mod?vv:vv-mod;
		return *this;
	}

	ModA(int64_t x=0){s(x%mod+mod);}

	ModA& operator+=(const ModA &x){return s(a+x.a);}
	ModA& operator-=(const ModA &x){return s(a+mod-x.a);}
	ModA& operator*=(const ModA &x){
		a=uint64_t(a)*x.a%mod;
		return *this;
	}
	ModA& operator/=(const ModA &x){
		*this*=x.inv();
		return *this;
	}

	ModA operator+(const ModA &x)const{return ModA(*this)+=x;}
	ModA operator-(const ModA &x)const{return ModA(*this)-=x;}
	ModA operator*(const ModA &x)const{return ModA(*this)*=x;}
	ModA operator/(const ModA &x)const{return ModA(*this)/=x;}
	bool operator==(const ModA &x)const{return a==x.a;}
	bool operator!=(const ModA &x)const{return a!=x.a;}
	bool operator<(const ModA &x)const{return a<x.a;}

	ModA operator-()const{return ModA()-*this;}
	ModA pow(int64_t n)const{
		ModA res(1),x(*this);
		while(n){
			if(n&1)res*=x;
			x*=x;
			n>>=1;
		}
		return res;
	}

	int64_t extgcd(int64_t p,int64_t q,int64_t &x,int64_t &y)const{
		if(q==0){
			x=1;
			y=0;
			return p;
		}
		int64_t g=extgcd(q,p%q,y,x);
		y-=(p/q)*x;
		return g;
	}

	ModA inv()const{
		int64_t x,y;
		assert(extgcd(a,mod,x,y)==1);
		return ModA(x);
	}
};
using aint=ModA;
uint32_t aint::mod=1000000007;
istream& operator>>(istream& in,const ModA& a){
	return (in>>a.a);
}
ostream& operator<<(ostream& out,const ModA& a){
	return (out<<a.a);
}

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

aint ten;
aint inv;
aint tenpow[222222];
aint invpow[222222];
aint accten[222222];
aint accinv[222222];
void calc(int v,aint t,aint i){
    accten[v]=t;
    accinv[v]=i;
    for(auto &e:wt[v]){
        if(e.to==wt.par(v))continue;
        calc(e.to,t+tenpow[wt.dep(v)]*e.cost,i+invpow[wt.dep(v)]*e.cost);
    }
}

int N;

int ans;
map<aint,int>cntten;
map<aint,int>cntinv;
namespace DSUOnTree{
    void check(int v,int b){
        aint z=-(accinv[v]-accinv[b])*tenpow[wt.dep(b)*2]*inv+accten[b];
        if(cntten.find(z)!=cntten.end())ans+=cntten[z];

        z=-(accten[v]-accten[b])*invpow[wt.dep(b)*2]*ten+accinv[b];
        if(cntinv.find(z)!=cntinv.end())ans+=cntinv[z];
    }
    void add(int v){
        cntten[accten[v]]++;
        cntinv[accinv[v]]++;
    }
    void dfs(int v,int p,bool keep){
        int hv=wt.heavy(v);
        for(auto &e:wt[v]){
            if(e.to!=p&&e.to!=hv)dfs(e.to,v,false);
        }

        if(hv!=-1)dfs(hv,v,true);
        check(v,v);
        add(v);
        for(auto &e:wt[v])if(e.to!=p&&e.to!=hv){
            for(int i=wt.tin(e.to);i<wt.tout(e.to);i++)check(wt.vs(i),v);
            for(int i=wt.tin(e.to);i<wt.tout(e.to);i++)add(wt.vs(i));
        }

        //calc

        if(!keep){
        //delete
            cntten.clear();
            cntinv.clear();
            // for(int i=wt.tin(v);i<wt.tout(v);i++){
            //     int u=wt.vs(i);
            //     //delete
            // }
        }
    }
    void solve(){
        dfs(0,-1,false);
    }
}

signed main(){
    int m;
    scanf("%lld%lld",&N,&m);
    aint::mod=m;

    ten=aint(10);
    inv=ten.inv();
    

    tenpow[0]=invpow[0]=1;
    for(int i=1;i<222222;i++){
        tenpow[i]=tenpow[i-1]*ten;
        invpow[i]=invpow[i-1]*inv;
    }
    wt.set(N);
    rep(i,N-1){
        int a,b,d;
        scanf("%lld%lld%lld",&a,&b,&d);
        wt.addEdge(a,b,d);
    }


    wt.init();
    calc(0,0,0);
    DSUOnTree::solve();

    cout<<ans<<endl;
    return 0;
}