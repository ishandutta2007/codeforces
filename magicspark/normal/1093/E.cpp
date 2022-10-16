/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
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
    #ifdef LOCAL
    int getint(){
    	int x;cin>>x;return x;
	}
	#else
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
    #endif
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
const int maxn=5e7;
unsigned long long F[maxn];
int top;
unsigned short G[maxn];
int new_node(){
	int x=++top;F[x]=G[x]=0;return x;
}
void Left(int x,int v){
	F[x]+=(ll)v<<28;
}
const int mask10=(1<<10)-1;
void Right(int x,int v){
	G[x]+=v>>10;F[x]+=((ll)v&mask10)<<54;
}
void Val(int x,int v){
	F[x]+=v;
}
const int mask28=(1<<28)-1;
const int mask26=(1<<26)-1;
int val(int x){
	return F[x]&mask28;
}
int ls(int x){
	return (F[x]>>28)&mask26;
}
int rs(int x){
	return ((int)G[x]<<10)+(F[x]>>54);
}
struct SGT{
	int root,ql,qr,qv,N;
	void init(int L,int R){
		N=R;root=new_node();
	}
	void go(int l,int r,int k){
		Val(k,qv);
		if(l==r)return;
		int mid=(l+r)/2;
		if(ql<=mid){
			if(!ls(k))Left(k,new_node());
			go(l,mid,ls(k));
		}else{
			if(!rs(k))Right(k,new_node());
			go(mid+1,r,rs(k));
		}
	}
	void add(int x,int v){
		ql=x;qv=v;go(1,N,root);
	}
	int query(int l,int r,int k){
		if(!k)return 0;
		if(r<ql||qr<l)return 0;
		if(ql<=l&&r<=qr)return val(k);
		return query(l,(l+r)/2,ls(k))+query((l+r)/2+1,r,rs(k));
	}
	int get_sum(int L,int R){
		ql=L;qr=R;return query(1,N,root);
	}
}f[200005];
void modify(int x,int v){
	while(x<=2e5){
		f[x].add(v,1);
		x+=x&-x;
	}
}
void del(int x,int v){
	while(x<=2e5){
		f[x].add(v,-1);
		x+=x&-x;
	}
}
int sum(int x,int v){
	int ret=0;
	while(x){
		ret+=f[x].get_sum(1,v);
		x-=x&-x;
	}
	return ret;
}
int query(int l,int r,int vl,int vr){
	return sum(r,vr)-sum(r,vl-1)-sum(l-1,vr)+sum(l-1,vl-1);
}
int n,q;
int a[200005],b[200005],to[200005];
int main(){
	n=getint();q=getint();
	for(int i=1;i<=n;i++)a[i]=getint(),to[a[i]]=i;
	for(int i=0;i<=2e5;i++)f[i].init(1,n);
	for(int i=1;i<=n;i++)b[i]=to[getint()],modify(i,b[i]);
	while(q--){
		int t=getint();
		if(t==1){
			int l=getint(),r=getint(),lb=getint(),rb=getint();
			putln(query(lb,rb,l,r));
		}else{
			int x=getint(),y=getint();
			del(x,b[x]);del(y,b[y]);
			swap(b[x],b[y]);
			modify(x,b[x]);
			modify(y,b[y]);
		}
	}
	clear();
	return 0;
}