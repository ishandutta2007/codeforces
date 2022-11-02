/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
int n,m,k;
int c[1000005],tot,col[1000005],bad[1000005];
vector<int>g[1000005];
vector<pair<int,int> >E;
void dfs(int x){
	for(auto to:g[x])if(!col[to]){
		col[to]=tot*4+1-col[x];
		dfs(to);
	}else if(col[to]==col[x]){
		bad[c[x]]=1;
	}
}
set<pair<int,int> >type;
set<int>occ;
int color[1000005];
vector<int>G[1000005];
bool go(int x){
	bool ret=1;
	for(auto to:G[x]){
		if(color[to]==-1){
			color[to]=1-color[x];ret&=go(to);
		}else{
			ret&=(color[to]!=color[x]);
		}
	}
	return ret;
}
bool solve(int l,int r){
//	cerr<<"solve: "<<l<<" "<<r<<endl;
	occ.clear();
	for(int i=l;i<=r;i++){
		occ.insert(col[E[i].first]);
		occ.insert(col[E[i].second]);
		occ.insert(col[E[i].first]^1);
		occ.insert(col[E[i].second]^1);
	}
	for(auto v:occ)color[v]=-1,color[v^1]=-1;
	for(auto v:occ)G[v].clear();
	for(int i=l;i<=r;i++){
		G[col[E[i].first]].push_back(col[E[i].second]);
		G[col[E[i].second]].push_back(col[E[i].first]);
		G[col[E[i].first]].push_back(col[E[i].first]^1);
		G[col[E[i].second]].push_back(col[E[i].second]^1);
		G[col[E[i].first]^1].push_back(col[E[i].first]);
		G[col[E[i].second]^1].push_back(col[E[i].second]);
	}
	for(auto v:occ)if(color[v]==-1){
		color[v]=0;
		if(!go(v))return false;
	}
//	cerr<<"good"<<endl;
	return true;
}
bool cmp(pair<int,int>x,pair<int,int>y){
	int lx=min(c[x.first],c[x.second]),rx=max(c[x.first],c[x.second]);
	int ly=min(c[y.first],c[y.second]),ry=max(c[y.first],c[y.second]);
	return make_pair(lx,rx)<make_pair(ly,ry);
}
bool is(pair<int,int>p,pair<int,int>pc){
	if(c[p.first]==pc.first&&c[p.second]==pc.second)return true;
	if(c[p.first]==pc.second&&c[p.second]==pc.first)return true;
	return false;
}
int main(){
	n=getint();m=getint();k=getint();
	for(int i=1;i<=n;i++)c[i]=getint();
	for(int i=1;i<=m;i++){
		int x=getint(),y=getint();
		if(c[x]==c[y]){
			g[x].push_back(y);
			g[y].push_back(x);
		}else{
			E.push_back(make_pair(x,y));
		}
	}
	for(int i=1;i<=n;i++){
		if(!col[i]){tot++;col[i]=tot*2;dfs(i);}
	}
//	for(auto p:E)cerr<<p.first<<" "<<p.second<<endl;
	sort(E.begin(),E.end(),cmp);
	int cnt=0;
	for(int i=1;i<=k;i++)if(!bad[i])cnt++;
	for(auto p:E){
		if(bad[c[p.first]]||bad[c[p.second]])continue;
		int l=min(c[p.first],c[p.second]),r=max(c[p.first],c[p.second]);
		type.insert(make_pair(l,r));
	}
	vector<pair<int,int> >EE=E;E.clear();
	for(auto p:EE){
		if(bad[c[p.first]]||bad[c[p.second]])continue;
		E.push_back(p);
	}
	int lst=0,pos=0;
	ll ans=1ll*cnt*(cnt-1)/2;
	for(auto p:type){
		while(pos<E.size()&&is(E[pos],p))pos++;
		if(pos!=lst){
			ans-=(solve(lst,pos-1)?0:1);
		}else{
			assert(0);
		}
		lst=pos;
	}
	cout<<ans<<endl;
	return 0;
}