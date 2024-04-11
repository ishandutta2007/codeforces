/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sufn.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_tot/assoc_container.hpp>
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
	struct Flusher_ {
		~Flusher_(){clear();}
	}io_flusher_;
}
using namespace fastio;
//using namespace __gnu_pbtot;
const int inf=0x3f3f3f3f;
const double eps=1e-9;
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
int n,q,x,y,ans;
vector<pair<int,int> >g[500005];
struct tree{
	ll dep[500005],ld[500005],mx[500005],lst[500005],bel[500005];
	ll f[20][500005],pre[500005],tot;
	pair<int,int>b[500005];
	void dfs(int x){
		for(int i=1;i<=19;i++)if(f[i-1][x])f[i][x]=f[i-1][f[i-1][x]];
		for(auto p:g[x])if(p.first!=f[0][x]){
			f[0][p.first]=x;dep[p.first]=dep[x]+p.second;dfs(p.first);
			if(ld[p.first]+p.second>ld[x]){
				ld[x]=ld[p.first]+p.second;mx[x]=p.first;
			}
		}
	}
	void dfs2(int x,int st){
		ld[x]=st;
		if(!mx[x]){lst[st]=x;b[tot++]=make_pair(dep[x]-dep[f[0][st]],st);return;}
		dfs2(mx[x],st);
		for(auto p:g[x])if(p.first!=f[0][x]&&p.first!=mx[x])dfs2(p.first,p.first);
	}
	void init(int rt){
		dfs(rt);dfs2(rt,rt);
		sort(b,b+tot);reverse(b,b+tot);
		for(int i=0;i<tot;i++)pre[i]=(i?pre[i-1]:0)+b[i].first,bel[b[i].second]=i;
//		for(int i=1;i<=n;i++)cerr<<ld[i]<<" ";cerr<<endl;
		for(int i=1;i<=n;i++)bel[i]=bel[ld[i]];
//		for(int i=1;i<=n;i++)cerr<<bel[i]<<" ";cerr<<endl;
	}
	ll query(){
		if(tot/2+1<=y)return pre[tot-1];
		y=(y-1)*2;
		if(bel[x]<=y)return pre[y];
		int z=x;
		for(int i=19;i>=0;i--)if(bel[f[i][z]]>y)z=f[i][z];
		z=f[0][z];
		return max(pre[y-1],pre[y]-dep[lst[ld[z]]]+dep[z])+dep[lst[ld[x]]]-dep[z];
	}
}t[2];
ll dep[500005];
void dfs(int x,int par){
	for(auto p:g[x])if(p.first!=par){
		dep[p.first]=dep[x]+p.second;
		dfs(p.first,x);
	}
}
signed main(){
//	freopen("bomb.in","r",stdin);
//	freopen("bomb.out","w",stdout);
	n=getint();q=getint();
	for(int i=1;i<n;i++){
		int x=getint(),y=getint(),z=getint();
		g[x].push_back(make_pair(y,z));
		g[y].push_back(make_pair(x,z));
	}
	dfs(1,0);
	int f1=max_element(dep+1,dep+n+1)-dep;
	t[0].init(f1);
	memset(dep,0,sizeof dep);
	dfs(f1,0);
	int f2=max_element(dep+1,dep+n+1)-dep;
	t[1].init(f2);
//	cerr<<f1<<" "<<f2<<endl;
	while(q--){
		x=getint();y=getint();
		x=(x+ans-1)%n+1;y=(y+ans-1)%n+1;
		if(t[0].dep[x]>t[1].dep[x])putln(ans=t[0].query());
		else putln(ans=t[1].query());
	}
	return 0;
}