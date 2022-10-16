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
//#pragma comment("-Wl,--stack=1024000000")
#include<ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-9;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
inline int Rand(){return rand()*32768+rand();}
map<int,int>mp;
int n,m,a[100005][5],b[100005][5],ord[100005],w[100005],f[100005*33],tot;
bool cmp(int x,int y){return w[x]<w[y];}
cc_hash_table<unsigned long long,int>mmp;
unsigned long long get_hash(vector<int>v){
	__int128 cur=0;
	for(auto u:v)cur=cur*533333+(u+1);
	unsigned long long u1,u2;
	u1=cur>>64;u2=(-1ull)&cur;
	return u1^u2;
}
int get_id(vector<int>vv){
	auto v=get_hash(vv);
	if(mmp.find(v)==mmp.end())mmp[v]=++tot,f[tot]=(vv.size()%2?-1:1);
	return mmp[v];
}
int bel[100005][32],cnta[100005*33],cntb[100005*33];
ll cur;
void add_a(int x){
	for(int i=0;i<(1<<m);i++){
		int tmp=bel[x][i];
		cur+=f[tmp]*cntb[tmp];
		cnta[tmp]++;
	}
}
void add_b(int x){
	for(int i=0;i<(1<<m);i++){
		int tmp=bel[x][i];
		cur+=f[tmp]*cnta[tmp];
		cntb[tmp]++;
	}
}
void del_b(int x){
	for(int i=0;i<(1<<m);i++){
		int tmp=bel[x][i];
		cur-=f[tmp]*cnta[tmp];
		cntb[tmp]--;
	}
}
int main(){
	n=getint();m=getint();
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++)a[i][j]=getint(),mp[a[i][j]];
		w[i]=getint();ord[i]=i;
	}
	sort(ord+1,ord+n+1,cmp);
	sort(w+1,w+n+1);
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++)b[i][j]=a[ord[i]][j];
	memcpy(a,b,sizeof a);
	for(auto &p:mp)p.second=++tot;
	for(int i=1;i<=n;i++)for(int j=0;j<m;j++)a[i][j]=mp[a[i][j]];
	tot=0;
	for(int i=1;i<=n;i++){
		sort(a[i],a[i]+m);
		for(int j=0;j<(1<<m);j++){
			vector<int>vv;
			for(int t=0;t<m;t++)if(j&(1<<t))vv.push_back(a[i][t]);
			bel[i][j]=get_id(vv);
		}
	}
	for(int i=1;i<=n;i++)add_b(i);
	int pos=n,ans=2e9+5;
	for(int i=1;i<=n;i++){
		add_a(i);
		while(pos>0&&cur>0)del_b(pos),pos--;
		while(pos<n&&cur<=0)pos++,add_b(pos);
		if(!cur)continue;
		ans=min(ans,w[i]+w[pos]);
	}
	if(ans==2e9+5)puts("-1");
	else cout<<ans<<endl;
	return 0;
}