/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
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
	struct Flusher_ {
		~Flusher_(){clear();}
	}io_flusher_;
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
vector<int>z_function(const string& s){
    int n=(int)s.size();
    vector<int>z(n);
    int l=0,r=1;
    for(int i=1;i<n;++i){
        if(i<r){
            z[i]=min(z[i-l],r-i);
        }
        while(i+z[i]<n&&s[z[i]]==s[i+z[i]]){
            ++z[i];
        }
        if (i+z[i]>=r){
            l=i;
            r=i+z[i];
        }
    }
    return z;
}
int maxlen[2000005],par[2000005],lst=1,tot=1,f[2000005],tr[2000005][26];
void extend(int id){
	int cur=++tot,p=lst;f[cur]=1;
	while(p&&!tr[p][id]){
		tr[p][id]=cur;
		p=par[p];
	}
	if(!p)par[cur]=1;
	else{
		int q=tr[p][id];
		if(maxlen[q]==maxlen[p]+1)par[cur]=q;
		else{
			int clone=++tot;
			memcpy(tr[clone],tr[q],sizeof tr[q]);
			par[clone]=par[q];
			maxlen[clone]=maxlen[p]+1;
			while(p&&tr[p][id]==q){
				tr[p][id]=clone;
				p=par[p];
			}
			par[q]=par[cur]=clone;
		}
	}
	lst=cur;
}
vector<int>g[2000005];
string all;
int n,len,can[1000005],state,lvl;
queue<int>q;
void dfs(int x){
	for(auto to:g[x]){
		dfs(to);f[x]+=f[to];
	}
}
void build(){
	for(int i=2;i<=tot;i++)g[par[i]].push_back(i);
	dfs(1);
}
void push(int id){
	q.push(id);
	while(!q.empty()){
		int x=q.front();
		if(!tr[state][x])break;
		state=tr[state][x];q.pop();
		lvl++; 
	}
}
void pop(){
	lvl--;
	if(maxlen[par[state]]>=lvl){
		state=par[state];
	}
	while(!q.empty()){
		int x=q.front();
		if(!tr[state][x])break;
		state=tr[state][x];q.pop();
		lvl++; 
	}
}
int main(){
	all=getstr();
	for(char c:all)extend(c-'a');
	build();
	int n=getint();
	while(n--){
		string s=getstr();len=s.size();s=s+s;
		state=1;lvl=0;int ans=0;
		while(!q.empty())q.pop();
		for(int i=0;i<len;i++){
			push(s[i]-'a');
		}
		set<int>pos;
		for(int i=0;i<len;i++){
			if(lvl==len)pos.insert(state);
			pop();push(s[i]-'a');
		}
		for(auto v:pos)ans+=f[v];
		cout<<ans<<endl;
	}
	return 0;
}