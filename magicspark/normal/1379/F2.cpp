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
typedef tree<pair<int,int>,null_type,less<pair<int,int> >,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int n,m,q;
ordered_set s[2][200005];
inline void update(int t,int x,int y,int tag){
	pair<int,int>ins(y,x);
	while(x<=n){
		if(tag==1)s[t][x].insert(ins);
		else s[t][x].erase(ins);
		x+=x&-x;
	}
}
inline int query0(int x,int y){
	//[1,x] [1,y]
	int ret=0;
	while(x){
		ret+=s[1][x].order_of_key(make_pair(y,inf));
		x-=x&-x;
	}
	return ret;
}
inline int query1(int x,int y){
	int ret=0;
	x--;
	while(x){
		ret-=s[0][x].size()-s[0][x].order_of_key(make_pair(y,0));
		x-=x&-x;
	}
	x=n;
	while(x){
		ret+=s[0][x].size()-s[0][x].order_of_key(make_pair(y,0));
		x-=x&-x;
	}
	return ret;
}
int main(){
	n=getint();m=getint();q=getint();
	ll cnt=0;
	set<pair<int,int> >ban;
	while(q--){
		int x=getint(),y=getint();
		int X=x,Y=y;
		x++;y++;
		int type=1-x%2;
		x/=2;y/=2;
		if(!ban.count(make_pair(X,Y))){
			update(type,x,y,1);
			ban.insert(make_pair(X,Y));
			if(type==0)cnt+=query0(x,y);
			else cnt+=query1(x,y);
		}else{
			update(type,x,y,-1);
			ban.erase(make_pair(X,Y));
			if(type==0)cnt-=query0(x,y);
			else cnt-=query1(x,y);
		}
		putstr(cnt?"NO\n":"YES\n");
	}
	clear();
	return 0;
}