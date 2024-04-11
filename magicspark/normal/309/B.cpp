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
            put('0');
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
#endif
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,r,c;
string s[1000005];
int len[1000005],nxt[1000005];
int pref[1000005];
vector<int>g[1000005];
void add_edge(int x,int y){
	g[y].push_back(x);
}
bool vis[1000005];
vector<int>stk;
int ans=-1,st;
void dfs(int x){
	vis[x]=1;stk.push_back(x);
	int sub=min((int)stk.size(),r+1);
	int pos=stk.size()-sub;
	if(stk[pos]-x>ans){
		ans=stk[pos]-x;
		st=x;
	}
	for(int i=0;i<g[x].size();i++){
		dfs(g[x][i]);
	}
	stk.pop_back();
}
int main(){
	n=getint();r=getint();c=getint()+1;
	for(int i=1;i<=n;i++)s[i]=getstr();
	for(int i=1;i<=n;i++)len[i]=s[i].size()+1;
	for(int i=1;i<=n;i++)pref[i]=pref[i-1]+len[i];
	for(int i=1;i<=n;i++){
		if(len[i]>c)continue;
		int L=i-1,R=n+1;
		while(R-L>1){
			int mid=L+R>>1;
			if(pref[mid]-pref[i-1]<=c)L=mid;
			else R=mid;
		}
		cerr<<R<<"--->"<<i<<" value="<<R-i<<endl;
		nxt[i]=R;add_edge(i,R);
	}
	for(int i=n+1;i>=1;i--)if(!vis[i])dfs(i);
	cerr<<st<<endl;
	for(int line=1;line<=r;line++){
		if(len[st]>c)break;
		for(int i=st;i<nxt[st];i++){
			if(i!=st)put(' ');putstr(s[i]);
		}
		put('\n');st=nxt[st];
	}
	clear();
	return 0;
}