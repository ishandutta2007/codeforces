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
#define int long long 
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
int n,m;
int a[500005];
int p[500005];
int b[500005];
#define SIZE 524288
int f[SIZE<<1],g[SIZE<<1];
int merge(int x,int y){
	return max(x,y);
}
void update(int x,int v){
	x+=SIZE;f[x]=v;
	while(x!=1){
		x>>=1;f[x]=merge(f[x<<1],f[x<<1|1]);
	}
}
void pushdown(int x){
	g[x<<1]+=g[x];g[x<<1|1]+=g[x];g[x]=0;
}
void pushup(int x){
	f[x]=max(f[x<<1]+g[x<<1],f[x<<1|1]+g[x<<1|1]);
}
void add(int l,int r,int k,const int &ql,const int &qr,const int &val){
	if(qr<l||r<ql)return;
	if(ql<=l&&r<=qr){
		g[k]+=val;
		return;
	}
	pushdown(k);
	add(l,(l+r)/2,k<<1,ql,qr,val);
	add((l+r)/2+1,r,k<<1|1,ql,qr,val);
	pushup(k);
}
int get(int x,int l=0,int r=SIZE-1,int k=1){
	if(l==r){return f[k]+g[k];}
	int mid=(l+r)/2;
	pushdown(k);
	if(x<=mid)return get(x,l,mid,k<<1);
	else return get(x,mid+1,r,k<<1|1);
}
signed main(){
	n=getint();
	for(int i=1;i<=n;i++)a[i]=getint();
	for(int i=1;i<=n;i++)p[i]=getint();
	m=getint();
	for(int i=1;i<=m;i++)b[i]=getint();b[m+1]=1e18;
	for(int i=0;i<=m;i++)update(i,1e18);update(0,0);
	for(int i=1;i<=n;i++){
		int pos=lower_bound(b+1,b+m+1,a[i])-b;
		if(b[pos]==a[i]){
			add(0,SIZE-1,1,pos,m,p[i]<0?p[i]:0);
			int pre=get(pos-1),now=get(pos);
			if(pre<now)add(0,SIZE-1,1,pos,pos,-now+pre);
			add(0,SIZE-1,1,0,pos-1,p[i]);
		}else{
			add(0,SIZE-1,1,pos,m,p[i]<0?p[i]:0);
			add(0,SIZE-1,1,0,pos-1,p[i]);
		}
//		for(int i=0;i<=m;i++)cerr<<get(i)<<" ";cerr<<endl;
	}
	int val=get(m);
	if(val>=1e16){
		puts("NO");
	}else{
		puts("YES");
		cout<<val<<endl;
	}
	return 0;
}