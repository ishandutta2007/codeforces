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
struct Node{
	int l,r,size,cnt,f[5];
	int key,rnd;
	Node(int _key=0){l=0;r=0;size=1;cnt=1;key=_key;rnd=Rand();memset(f,0,sizeof f);f[0]=key;}
}node[100005];
int tot,root;
void init(){
	tot=0;root=0;srand(time(0));
	node[0].cnt=0;node[0].size=0;
}
int new_node(int v){
	node[++tot]=Node(v);return tot;
}
void update(int v){
	int szl=node[node[v].l].size,szm=1;
	node[v].size=node[v].cnt+node[node[v].l].size+node[node[v].r].size;
//	cerr<<v<<" "<<node[v].l<<" "<<node[v].r<<endl;
	memset(node[v].f,0,sizeof node[v].f);
	node[v].f[szl%5]=node[v].key;
	for(int i=0;i<5;i++){
		node[v].f[i]+=node[node[v].l].f[i];
		node[v].f[(i+szl+szm)%5]+=node[node[v].r].f[i];
	}
//	cerr<<v<<" "<<node[v].l<<" "<<node[v].r<<endl;
//	for(int i=0;i<5;i++)cerr<<node[v].f[i]<<" ";cerr<<endl;
//	cerr<<"-----------------\n";
}
void split(int &rt1,int &rt2,int rt,int x){
	//rt1:key<=x
	//rt2:key>x
	if(!rt){rt1=rt2=0;return;}
	if(node[rt].key<=x){
		rt1=rt;split(node[rt].r,rt2,node[rt].r,x);
	}else{
		rt2=rt;split(rt1,node[rt].l,node[rt].l,x);
	}
	update(rt);
}
int merge(int x,int y){
	//min->x max->y
	if(!x)return y;
	if(!y)return x;
	//merge by min heap
	if(node[x].rnd<node[y].rnd){
		node[x].r=merge(node[x].r,y);
		update(x);return x;
	}else{
		node[y].l=merge(x,node[y].l);
		update(y);return y;
	}
}
void insert(int &rt,int x){
	int rtl=0,rtr=0,rtv=0;
	split(rtl,rtr,rt,x);
	split(rtl,rtv,rtl,x-1);
	if(!rtv)rtv=new_node(x);
	else node[rtv].cnt++;
	update(rtv);
	rt=merge(rtl,merge(rtv,rtr));
}
void erase(int &rt,int x){
	int rtl=0,rtr=0,rtv=0;
	split(rtl,rtr,rt,x);
	split(rtl,rtv,rtl,x-1);
	if(!rtv)return;
	node[rtv].cnt--;
	update(rtv);
	if(!node[rtv].cnt){
		rt=merge(rtl,rtr);
	}else{
		rt=merge(rtl,merge(rtv,rtr));
	}
}
int get_rank(int &rt,int x){
	int rtl=0,rtr=0;
	split(rtl,rtr,rt,x-1);
	int ret=node[rtl].size+1;
	rt=merge(rtl,rtr);
	return ret;
}
int get_kth(int &rt,int x){
	int l=node[rt].l,r=node[rt].r;
	if(x<=node[l].size)return get_kth(l,x);
	else if(x<=node[l].size+node[rt].cnt)return node[rt].key;
	else return get_kth(r,x-node[l].size-node[rt].cnt);
}
int get_pre(int &rt,int x){
	int rtl=0,rtr=0;
	split(rtl,rtr,rt,x-1);
	int ret=get_kth(rtl,node[rtl].size);
	rt=merge(rtl,rtr);
	return ret;
}
int get_suf(int &rt,int x){
	int rtl=0,rtr=0;
	split(rtl,rtr,rt,x);
	int ret=get_kth(rtr,1);
	rt=merge(rtl,rtr);
	return ret;
}
int get_type(){
	string s=getstr();
	if(s=="add")return 0;
	if(s=="del")return 1;
	if(s=="sum")return 2;
}
signed main(){
	init();
	int Q=getint();
	while(Q--){
		int type=get_type(),x;
		if(type!=2)x=getint();
		if(type==0)insert(root,x);
		if(type==1)erase(root,x);
		if(type==2)putln(node[root].f[2]);
	}
	clear();
	return 0;
}