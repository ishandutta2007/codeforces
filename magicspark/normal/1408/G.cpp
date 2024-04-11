/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
const int mod=998244353;
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
int n;
int a[1505][1505];
int x[1555555],y[1555555];
int par[1505],id[1505],cnt[1505][1505],sz[1505];
vector<vector<int> >cc;
bool can[6666];
vector<int>g[6666];
int find(int x){
	return x==par[x]?x:par[x]=find(par[x]);
}
void merge(int x,int y){
	x=find(x);y=find(y);
	cnt[x][y]++;
	cnt[y][x]++;
	if(cnt[x][y]==sz[x]*sz[y]){
		par[x]=y;sz[y]+=sz[x];
		for(int i=1;i<=n;i++){
			cnt[i][y]+=cnt[i][x];
			cnt[y][i]+=cnt[x][i];
		}
		vector<int>add;
		for(int i=1;i<=n;i++){
			if(find(i)==y){
				add.push_back(i);
			}
		}
		can[cc.size()]=1;
		for(int i=1;i<=n;i++){
			if(find(i)==i&&i!=x&&i!=y){
				if(cnt[i][x]||cnt[i][y])can[cc.size()]=0;
			}
		}
		g[cc.size()].push_back(id[x]);
		g[cc.size()].push_back(id[y]);
		id[y]=cc.size();
		cc.push_back(add);
	}
}
int dp[6000][1505],tdp[1505];
inline void add(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
}
void dfs(int x){
	if(cc[x].size()==1){
		dp[x][1]=1;
		return;
	}
	dfs(g[x][0]);
	dfs(g[x][1]);
	int szl=cc[g[x][0]].size(),szr=cc[g[x][1]].size();
	for(int i=szr;i>=0;i--){
		for(int j=szl;j>=0;j--){
			add(dp[x][i+j],1ll*dp[g[x][0]][j]*dp[g[x][1]][i]%mod);
		}
	}
	if(can[x])dp[x][1]++;
	for(int i=1;i<=n;i++){
		cerr<<x<<" "<<i<<" "<<dp[x][i]<<endl;
	}
}
int main(){
	#ifdef LOCAL
		freopen("input.txt","r",stdin);
	#endif
	n=getint();
	for(int i=1;i<=n;i++)cc.push_back({i});
	for(int i=1;i<=n;i++)par[i]=i,sz[i]=1,id[i]=i-1,can[i-1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=getint();
			if(i<j){x[a[i][j]]=i;y[a[i][j]]=j;}
		}
	}
	for(int i=1;i<=n*(n-1)/2;i++){
		merge(x[i],y[i]);
	}
	for(auto v:cc){
		for(auto u:v)cerr<<u<<" ";cerr<<endl;
	}
	int rt=cc.size()-1;
	dfs(rt);
	for(int i=1;i<=n;i++)cout<<dp[rt][i]<<" ";
	return 0;
}