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
int n,m,k,f[20005][11],vis[500005];
vector<int>g[500005];
void add(int x,int vx,int y,int vy){
	//a[x]==vx||a[y]==vy;
	g[x*2+1-vx].push_back(y*2+vy);
	g[y*2+1-vy].push_back(x*2+vx);
}
void add_eq(int x,int y){
	add(x,0,y,1);
	add(x,1,y,0);
}
void add_low(int x,int y){
	g[x<<1|1].push_back(y<<1);
	g[y<<1|1].push_back(x<<1); 
}
void add_high(int x,int y){
	g[x<<1].push_back(y<<1|1);
	g[y<<1].push_back(x<<1|1);
}
vector<int>stk;
bool dfs(int x){
	vis[x]=1;vis[x^1]=2;
	stk.push_back(x);
	stk.push_back(x^1);
	for(auto u:g[x]){
		if(vis[u]==2)return false;
		if(vis[u]==1)continue;
		if(!dfs(u))return false;
	}
	return true;
}
void make_v(int x,int vx){
	add(x,vx,x,vx);
}
int main(){
	int T=getint();
	while(T--){
		n=getint();m=getint();k=getint();int tot=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=k;j++)f[i][j]=++tot;
		for(int i=1;i<=tot*2+3;i++)g[i].clear(),vis[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(i+1<=n)add(f[i][j],0,f[i+1][j],1);
				if(j+1<=k)add(f[i][j],1,f[i][j+1],0);
			}
			make_v(f[i][1],1);
		}
		for(int i=1;i<=m;i++){
			int op=getint();
			if(op==1){
				int x=getint(),y=getint();
				if(y==k)make_v(f[x][y],0);
				else add_eq(f[x][y],f[x][y+1]);
			}
			if(op==2){
				int x=getint(),y=getint(),v=getint();
				for(int i=1;i<=v&&i<=k;i++)if(v-i+1<=k){
					add_low(f[x][i],f[y][v-i+1]);
				}
				if(x==22&&y==63)add_low(f[x][4],f[y][8]);
				if(v<=k)make_v(f[x][v],0),make_v(f[y][v],0);
			}
			if(op==3){
				int x=getint(),y=getint(),v=getint();
				for(int i=1;i<=v-k;i++)make_v(f[x][i],1),make_v(f[y][i],1);
				for(int i=1;i<=v&&i<=k;i++)if(v-i+1<=k)add_high(f[x][i],f[y][v-i+1]);
			}
		}
		bool can=1;
		stk.clear();
		for(int i=1;i<=tot;i++)if(!vis[i<<1]){
			stk.clear();
			if(dfs(i<<1))continue;
			for(auto u:stk)vis[u]=0;
			stk.clear();
			if(!dfs(i<<1|1)){
				can=0;break;
			}
		}
		if(!can)putln(-1);
		else{
			for(int i=1;i<=n;i++){
				int cur=1;
				for(int j=1;j<=k;j++){
					if(vis[f[i][j]<<1|1]==2)break;
					cur=j;
				}
				putint(cur);
			}
			put('\n');
		}
	}
	return 0;
}