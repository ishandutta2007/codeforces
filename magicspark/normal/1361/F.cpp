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
#include<ext/pb_ds/assoc_container.hpp>
#define int long long
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
using namespace __gnu_pbds;
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
int n,q,p[200005],w[200005],tot,ls[500005],rs[500005],f1[500005],f2[500005],pos[200005],par[500005];
tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update>T[500005];
int ans=0;
int solve(int l,int r,int pr){
	if(l>r){
		int ind=++tot;
		T[ind].insert(p[l]);
		pos[l]=ind;
		par[ind]=pr;
		return ind;
	}
	pair<int,int>p(inf,inf);
	for(int i=l;i<=r;i++){
		p=min(p,make_pair(w[i],i));
	}
	int ind=++tot;par[ind]=pr;
	int vl=solve(l,p.second-1,ind);
	int vr=solve(p.second+1,r,ind);
	for(auto v:T[vl])T[ind].insert(v);
	for(auto v:T[vr])T[ind].insert(v);
	int sum=(ll)T[vl].size()*(ll)T[vr].size(),add=0;
	for(auto v:T[vr])add+=T[vl].order_of_key(v);
	f2[ind]=add;f1[ind]=sum-add;
	ans+=min(f1[ind],f2[ind]);
	ls[ind]=vl;rs[ind]=vr;
	return ind;
}
void del(int x,int v){
	cerr<<"delete: "<<x<<" "<<v<<endl;
	T[x].erase(v);
	while(par[x]!=-1){
		int p=par[x];ans-=min(f1[p],f2[p]);
		if(ls[p]==x){
			f1[p]-=T[rs[p]].order_of_key(v);
			f2[p]-=T[rs[p]].size()-T[rs[p]].order_of_key(v);
		}else{
			f1[p]-=T[ls[p]].size()-T[ls[p]].order_of_key(v);
			f2[p]-=T[ls[p]].order_of_key(v);
		}
		ans+=min(f1[p],f2[p]);
		x=par[x];T[x].erase(v);
	}
}
void ins(int x,int v){
	cerr<<"insert: "<<x<<" "<<v<<endl;
	T[x].insert(v);
	while(par[x]!=-1){
		int p=par[x];ans-=min(f1[p],f2[p]);
		if(ls[p]==x){
			f1[p]+=T[rs[p]].order_of_key(v);
			f2[p]+=T[rs[p]].size()-T[rs[p]].order_of_key(v);
		}else{
			f1[p]+=T[ls[p]].size()-T[ls[p]].order_of_key(v);
			f2[p]+=T[ls[p]].order_of_key(v);
		}
		ans+=min(f1[p],f2[p]);
		x=par[x];T[x].insert(v);
	}
}
//order of key(x) --->count v<x 
signed main(){
	n=getint();
	for(int i=1;i<=n;i++)p[i]=getint();
	for(int i=1;i<n;i++)w[i]=getint();
	int rt=solve(1,n-1,-1);
	q=getint();
	while(q--){
		int x=getint(),y=getint();
		del(pos[x],p[x]);
		del(pos[y],p[y]);
		swap(p[x],p[y]);
		ins(pos[x],p[x]);
		ins(pos[y],p[y]);
		putln(ans);
	}
	clear();
	return 0;
}