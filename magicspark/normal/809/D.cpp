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
int n;
struct Node{
	int key,rnd,l,r,size,lazy;
	Node(int _key=0){
		key=_key;rnd=Rand();l=0;r=0;size=1;lazy=0;
	}
}node[3000005];
int tot,root;
void init(){tot=0;root=0;node[0].size=0;}
int new_node(int v){node[++tot]=Node(v);return tot;}
void pushdown(int x){
	if(node[x].l)node[node[x].l].lazy+=node[x].lazy;
	if(node[x].r)node[node[x].r].lazy+=node[x].lazy;
	node[x].key+=node[x].lazy;node[x].lazy=0;
}
void update(int x){node[x].size=node[node[x].l].size+node[node[x].r].size+1;}
void split(int &rt1,int &rt2,int rt,int x){
	if(!rt){rt1=rt2=0;return;}
	pushdown(rt);
	if(node[rt].key<=x){
		rt1=rt;split(node[rt].r,rt2,node[rt].r,x);
	}else{
		rt2=rt;split(rt1,node[rt].l,node[rt].l,x);
	}
	update(rt);
}
int merge(int x,int y){
	if(!x||!y)return x+y;
	if(node[x].rnd<node[y].rnd){
		pushdown(x);
		node[x].r=merge(node[x].r,y);
		update(x);return x;
	}else{
		pushdown(y);
		node[y].l=merge(x,node[y].l);
		update(y);return y;
	}
}
void insert(int &rt,int x){
	int rtl=0,rtr=0;
	split(rtl,rtr,root,x);
	rt=merge(rtl,merge(new_node(x),rtr));
}
void erase(int &rt,int x){
	int rtl=0,rtr=0,rtv=0;
	split(rtl,rtr,rt,x);
	split(rtl,rtv,rtl,x-1);
	if(!rtv)return;
	root=merge(rtl,rtr);
}
int get_kth(int &rt,int x){
	int l=node[rt].l,r=node[rt].r;
	if(x<=node[l].size)return get_kth(l,x);
	else if(x<=node[l].size+1)return node[rt].key;
	else return get_kth(r,x-node[l].size-1);
}
int bs(int x,int v){
	if(x==0)return 0;pushdown(x);
	if(node[x].key<=v)return node[node[x].l].size+1+bs(node[x].r,v);
	else return bs(node[x].l,v);
}
void range_move(int l,int r,int vl){
	if(r<node[root].size)erase(root,get_kth(root,r+1));
	insert(root,vl-1);
}
void range_add(int rt,int l,int r,int ql,int qr){
	if(r<ql||qr<l)return;
	if(ql<=l&&r<=qr){
		node[rt].lazy++;
		return;
	}
	pushdown(rt);
	if(ql<=l+node[node[rt].l].size&&qr>=l+node[node[rt].l].size)node[rt].key++;
	range_add(node[rt].l,l,l+node[node[rt].l].size-1,ql,qr);
	range_add(node[rt].r,r-node[node[rt].r].size+1,r,ql,qr);
}
void print(int x){
	if(!x)return;
	pushdown(x);
	print(node[x].l);
	cerr<<node[x].key+node[x].lazy<<" ";
	print(node[x].r);
}
int main(){
	init();
	n=getint();insert(root,0);
	for(int i=1;i<=n;i++){
		int l=getint(),r=getint();
		int pos1=bs(root,l-1);
		int pos2=bs(root,r-1);
		range_move(pos1,pos2,l);
		range_add(root,1,node[root].size,pos1+1,pos2+1);
//		cerr<<"after "<<i<<" turns"<<" "<<l<<" "<<r<<" "<<pos1+1<<" "<<pos2+1<<endl;
//		print(root);cerr<<endl;
//		cerr<<"-------"<<endl;
	}
	putln(node[root].size-1);clear();
	return 0;
}