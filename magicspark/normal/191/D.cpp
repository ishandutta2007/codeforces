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
vector<int>g[400005];
int n,m,cnt[400005],x[1000005],y[1000005],pos[400005],vis[400005],dep[400005],p[400005];
ll sz[400005],ans;
bool ban[400005];
int nxt[2000005],hd[2000005],to[2000005],tot;
void add(int x,int y){
	tot++;nxt[tot]=hd[x];to[tot]=y;hd[x]=tot;
}
void dfs(int x,int par){
	vis[x]=1;dep[x]=dep[par]+1;
	int cur=1; 
	for(int t=hd[x];t;t=nxt[t]){
//		cerr<<cur<<endl;
		int to=::to[t];
		if(to==par){
			cur--;
			if(cur==0)continue;
		}
		if(vis[to]){
			if(dep[to]<dep[x]){
				ban[x]^=1;
				ban[to]^=1;
			}
		}else{
			dfs(to,x);
			ban[x]^=ban[to];
			if(ban[to])p[x]=p[to];
		}
	}
}
signed main(){
	n=getint();m=getint();
	for(int i=1;i<=n;i++)p[i]=i;
	for(int i=1;i<=m;i++){
		x[i]=getint();y[i]=getint();
		add(x[i],y[i]);
		add(y[i],x[i]);
		cnt[x[i]]++;cnt[y[i]]++;
	}
	ans=m;
	for(int i=1;i<=n;i++)ans-=cnt[i]/2;
//	for(int i=1;i<=n;i++)g[i].resize(cnt[i]);
//	for(int i=1;i<=m;i++){
//		g[x[i]][pos[x[i]]++]=y[i];
//		g[y[i]][pos[y[i]]++]=x[i];
//	}
	dfs(1,0);
	for(int i=1;i<=n;i++){
		sz[p[i]]+=1e9;
		if(cnt[i]>2)sz[p[i]]++;
	}
	memset(vis,0,sizeof vis);
	for(int x=1;x<=n;x++)if(p[x]==x){
		if((sz[x]%1000000000)<=1&&sz[x]>=2e9)ans++;
	}
	if(m==0)puts("0 0");
	else cout<<max(1ll,ans)<<" "<<m<<endl;
	return 0;
}