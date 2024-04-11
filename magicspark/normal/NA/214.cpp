/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
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
        while(ch==' '||ch=='\n')ch=get();
        while(ch!=' '&&ch!='\n')ret.push_back(ch),ch=get();
        return ret;
    }
    void putstr(string s){
        for(int i=0;i<s.size();i++)put(s[i]);
    }
    void putint(int x){
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
    void putln(int x){
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
}
using namespace fastio;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
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
int n,l,w;
vector<pair<int,int> >g[100005];
bool vis[100005];
int sz[100005];
ll ans;
void dfs_sz(int x,int par){
	sz[x]=1;
	for(auto p:g[x]){
		int to=p.first;
		if(!vis[to]&&to!=par){
			dfs_sz(to,x);
			sz[x]+=sz[to];
		}
	}
}
void find_root(int &x,int val){
	int prv=-1;
	while(1){
		bool hv=0;
		for(auto p:g[x]){
			int to=p.first;
			if(vis[to])continue;
			if(to==prv)continue;
			if(sz[to]*2>=val){
				prv=x;x=to;
				hv=1;break;
			}
		}
		if(!hv)break;
	}
}
void dfs_dist(int x,int par,vector<pair<int,int> >&all,int W,int L){
	for(auto p:g[x]){
		int to=p.first;
		if(!vis[to]&&to!=par){
			dfs_dist(to,x,all,W+p.second,L+1);
		}
	}
	all.push_back(make_pair(W,L));
}
struct BIT{
	int f[100005],bitn;
	void init(int nn){
		bitn=nn+2;
		for(int i=0;i<=bitn;i++)f[i]=0;
	}
	void add(int x,int v){
		x++;
		while(x<=bitn){
			f[x]+=v;
			x+=x&-x;
		}
	}
	int sum(int x){
		x++;
		if(x<=0)return 0;
		int ret=0;
		while(x){
			ret+=f[x];
			x-=x&-x;
		}
		return ret;
	}
}T;
vector<int>qry[100005];
int calc(vector<pair<int,int> >vec,int mul){
	T.init(vec.size());
	sort(vec.begin(),vec.end()); 
	for(int i=0;i<vec.size();i++){
		int L=-1,R=vec.size();
		while(R-L>1){
			int mid=(L+R)/2;
			if(vec[mid].first+vec[i].first>w)R=mid;
			else L=mid;
		}
		if(L>=0&&vec[i].second<=l)qry[L].push_back(l-vec[i].second);
	}
	for(int i=0;i<vec.size();i++){
		T.add(vec[i].second,1);
		for(auto v:qry[i]){
//			cerr<<T.sum(v)<<" "<<vec.size()<<endl;
			ans+=T.sum(min(v,T.bitn-1))*mul;
		}
	}
	for(int i=0;i<vec.size();i++)qry[i].clear();
}
void solve(int x){
	dfs_sz(x,-1);
	find_root(x,sz[x]);
//	cerr<<"solve: "<<x<<endl;
	vector<pair<int,int> >all;
	all.push_back(make_pair(0,0));
	vis[x]=1;
	for(auto p:g[x]){
		int to=p.first;
		if(vis[to])continue;
		vector<pair<int,int> >tmp;
		dfs_dist(to,x,tmp,p.second,1);
		calc(tmp,-1);
		for(auto v:tmp)all.push_back(v);
	}
	calc(all,1);
	for(auto p:g[x]){
		int to=p.first;
		if(vis[to])continue;
		solve(to);
	}
}
int main(){
	n=getint();l=getint();w=getint();
	for(int i=2;i<=n;i++){
		int p=getint(),q=getint();
		g[i].push_back(make_pair(p,q));
		g[p].push_back(make_pair(i,q));
	}
	solve(1);
//	cerr<<ans<<endl;
	cout<<(ans-n)/2<<endl;
	return 0;
}