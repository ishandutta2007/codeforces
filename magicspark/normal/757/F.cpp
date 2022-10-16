/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
namespace fastio{
    char in[100000];
    int itr=0,llen=0;
    char get(){
        if(itr==llen)llen=fread(in,1,100000,stdin),itr=0;
        if(llen==0)return EOF;
        return in[itr++];
    }
    char out[100000];
    int itr2=0;
    void put(char c){
        out[itr2++]=c;
        if(itr2==100000){
            fwrite(out,1,100000,stdout);
            itr2=0;
        }
    }
    int clear(){
        fwrite(out,1,itr2,stdout);
        itr2=0;
        return 0;
    }
    int getint(){
        int ret=0;char ch=get();
        if(ch=='-')return -getint();
        while (ch<'0'||ch>'9'){
            ch=get();if(ch=='-')return -getint();
        }
        while ('0'<=ch&&ch<='9'){
            ret=ret*10-48+ch;
            ch=get();
        }
        return ret;
    }
    string getstr(){
        string ret="";
        char ch=get();
        while(isspace(ch))ch=get();
        while(!isspace(ch))ret.push_back(ch),ch=get();
        return ret;
    }
    void putstr(string s){
        for(int i=0;i<s.size();i++)put(s[i]);
    }
    template<class T>void putint(T x){
        if(x<0){
            put('-');
            putint(-x);
            return;
        }
        if(x==0){
            put('0');put(' ');
            return;
        }
        char c[40];int pos=0;
        while(x){
            c[pos++]='0'+x%10;
            x/=10;
        }
        for(int i=pos-1;i>=0;i--)put(c[i]);
        put(' ');
    }
    template<class T>void putln(T x){
        if(x<0){
            put('-');
            putln(-x);
            return;
        }
        if(x==0){
            put('0');put('\n');
            return;
        }
        char c[40];int pos=0;
        while(x){
            c[pos++]='0'+x%10;
            x/=10;
        }
        for(int i=pos-1;i>=0;i--)put(c[i]);
        put('\n');
    }
	struct Flusher_ {
		~Flusher_(){clear();}
	}io_flusher_;
}
using namespace fastio;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n,m,x;
vector<pair<int,int> >g[200005];
vector<int>tr[200005];
int dist[200005];
vector<int>order;
int par[20][200005],dep[200005];
int get_lca(int x,int y){
	if(dep[x]<dep[y])swap(x,y);
	for(int i=0;i<20;i++)if((dep[x]-dep[y])&(1<<i))x=par[i][x];
	if(x==y)return x;
	for(int i=19;i>=0;i--){
		if(par[i][x]!=par[i][y]){
			x=par[i][x];
			y=par[i][y];
		}
	}
	return par[0][x];
}
int dfs(int x){
	int ret=1;
	for(auto u:tr[x])ret+=dfs(u);
	return ret;
}
signed main(){
	n=getint();m=getint();x=getint();
	for(int i=1;i<=m;i++){
		int x=getint(),y=getint(),z=getint();
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));
	}
	memset(dist,inf,sizeof dist);
	set<pair<int,int> >s;dist[x]=0;
	s.insert(make_pair(0,x));
	while(!s.empty()){
		int x=s.begin()->second,len=s.begin()->first;s.erase(s.begin());
		if(dist[x]!=len)continue;
		if(x!=::x){
		int cur=0;
		for(auto p:g[x])if(dist[p.first]+p.second==dist[x]){
			if(cur==0)cur=p.first;
			else cur=get_lca(cur,p.first);
		}
		par[0][x]=cur;dep[x]=dep[cur]+1;
		tr[cur].push_back(x);
		for(int i=1;i<20;i++)par[i][x]=par[i-1][par[i-1][x]];
		}
		for(auto p:g[x]){
			int to=p.first,cost=p.second;
			if(dist[to]>dist[x]+cost){
				dist[to]=dist[x]+cost;
				s.insert(make_pair(dist[to],to));
			}
		}
	}
	int ans=0;
	for(auto u:tr[x])ans=max(ans,dfs(u));
	cout<<ans<<endl;
	return 0;
}